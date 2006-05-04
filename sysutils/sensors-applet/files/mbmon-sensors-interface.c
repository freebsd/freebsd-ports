/*
 * Copyright (C) 2006 Jean-Yves Lefort <jylefort@FreeBSD.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdlib.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "mbmon-sensors-interface.h"
#include "sensors-applet.h"

static struct
{
  const char	*name;
  const char	*label;
  SensorType	type;
  const char	*icon;
  double	value;
} mbmon_sensors[] = {
  { "TEMP0",	N_("Main Board"),	TEMP_SENSOR,	MEM_ICON	},
  { "TEMP1",	N_("CPU"),		TEMP_SENSOR,	CPU_ICON	},
  { "TEMP2",	N_("PSU"),		TEMP_SENSOR,	CASE_ICON	},
  { "FAN0",	N_("Main Board Fan"),	FAN_SENSOR,	FAN_ICON	},
  { "FAN1",	N_("CPU Fan"),		FAN_SENSOR,	FAN_ICON	},
  { "FAN2",	N_("PSU Fan"),		FAN_SENSOR,	FAN_ICON	},
  { "VC0",	N_("Vc0"),		VOLTAGE_SENSOR,	VOLTAGE_ICON	},
  { "VC1",	N_("Vc1"),		VOLTAGE_SENSOR,	VOLTAGE_ICON	},
  { "V33",	N_("V33"),		VOLTAGE_SENSOR,	VOLTAGE_ICON	},
  { "V50P",	N_("V50P"),		VOLTAGE_SENSOR,	VOLTAGE_ICON	},
  { "V12P",	N_("V12P"),		VOLTAGE_SENSOR,	VOLTAGE_ICON	},
  { "V12N",	N_("V12N"),		VOLTAGE_SENSOR,	VOLTAGE_ICON	},
  { "V50N",	N_("V50N"),		VOLTAGE_SENSOR,	VOLTAGE_ICON	}
};

static gboolean
mbmon_sensors_interface_watch_cb (GIOChannel *source,
				  GIOCondition condition,
				  gpointer user_data)
{
  char *line;
  gsize terminator;

  while (g_io_channel_read_line(source, &line, NULL, &terminator, NULL) == G_IO_STATUS_NORMAL)
    {
      char *space;

      line[terminator] = 0;

      space = strchr(line, ' ');
      if (space)
	{
	  int name_len;
	  int i;

	  name_len = space - line;
	  for (i = 0; i < G_N_ELEMENTS(mbmon_sensors); i++)
	    if (! strncmp(mbmon_sensors[i].name, line, name_len))
	      {
		char *value_start;

		value_start = strstr(space + 1, ": ");
		if (value_start)
		  {
		    double value;
		    char *end;

		    value = strtod(value_start + 2, &end);
		    if (*end == 0)
		      mbmon_sensors[i].value = value;
		  }

		break;
	      }
	}

      g_free(line);
    }

  return TRUE;			/* keep source */
}

void
mbmon_sensors_interface_init (SensorsApplet *sensors_applet)
{
  GError *err = NULL;
  char *argv[] = { MBMON_EXECUTABLE, "-r", "10", NULL };
  int mbmon_stdout;
  GIOChannel *channel;
  int i;
  
  sensors_applet_register_sensors_interface(sensors_applet,
					    MBMON,
					    mbmon_sensors_interface_get_sensor_value);

  if (! g_spawn_async_with_pipes(NULL,
				 argv,
				 NULL,
				 0,
				 NULL,
				 NULL,
				 NULL,
				 NULL,
				 &mbmon_stdout,
				 NULL,
				 &err))
    {
      g_warning("Unable to execute mbmon: %s", err->message);
      g_error_free(err);
      return;
    }

  channel = g_io_channel_unix_new(mbmon_stdout);
  g_io_channel_set_flags(channel, G_IO_FLAG_NONBLOCK, NULL);
  g_io_add_watch(channel, G_IO_IN, mbmon_sensors_interface_watch_cb, NULL);

  for (i = 0; i < G_N_ELEMENTS(mbmon_sensors); i++)
    {
      char *path;

      path = g_strdup_printf("/mbmon/%s", mbmon_sensors[i].name);
      sensors_applet_add_sensor(sensors_applet,
				path,
				mbmon_sensors[i].name,
				mbmon_sensors[i].label,
				MBMON,
				TRUE,
				mbmon_sensors[i].type,
				mbmon_sensors[i].icon);
      g_free(path);
    }
}

double
mbmon_sensors_interface_get_sensor_value (const gchar *path, 
					  const gchar *id, 
					  SensorType type,
					  GError **error)
{
  int i;

  for (i = 0; i < G_N_ELEMENTS(mbmon_sensors); i++)
    if (! strcmp(mbmon_sensors[i].name, id))
      return mbmon_sensors[i].value;

  g_set_error(error, 0, 0, "Unknown sensor \"%s\"", id);
  return 0;
}
