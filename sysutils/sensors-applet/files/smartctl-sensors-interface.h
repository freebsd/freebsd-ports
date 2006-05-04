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

#ifndef SMARTCTL_SENSORS_INTERFACE_H
#define SMARTCTL_SENSORS_INTERFACE_H

#include "sensors-applet.h"

void smartctl_sensors_interface_init (SensorsApplet *sensors_applet);
double smartctl_sensors_interface_get_sensor_value (const gchar *path, 
						    const gchar *id, 
						    SensorType type,
						    GError **error);

#endif /* SMARTCTL_SENSORS_INTERFACE_H*/
