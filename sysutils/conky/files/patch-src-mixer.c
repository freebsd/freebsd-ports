--- src/mixer.c.orig
+++ src/mixer.c
@@ -38,9 +38,6 @@
 #include <ctype.h>
 
 
-#ifdef MIXER_IS_ALSA
-#include <alsa/asoundlib.h>
-#else
 #ifdef HAVE_LINUX_SOUNDCARD_H
 #include <linux/soundcard.h>
 #else
@@ -50,173 +47,12 @@
 #include <sys/soundcard.h>
 #endif /* __OpenBSD__ */
 #endif /* HAVE_LINUX_SOUNDCARD_H */
-#endif /* MIXER_IS_ALSA */
 
 #define MIXER_DEV "/dev/mixer"
 
-#ifdef MIXER_IS_ALSA
-#define MAX_MIXERS 8
-struct mixer_control {
-	char name[64];
-	snd_mixer_t *mixer;
-	snd_mixer_selem_id_t *sid;
-	snd_mixer_elem_t *elem;
-	long vol_min, vol_max;
-};
-
-static struct mixer_control mixer_data[MAX_MIXERS];
-int num_mixers = 0;
-static char soundcard[64] = "default";
-#else
 static int mixer_fd;
 static const char *devs[] = SOUND_DEVICE_NAMES;
-#endif
-
-#ifdef MIXER_IS_ALSA
-static int parse_simple_id(const char *str, snd_mixer_selem_id_t *sid)
-{
-	int c, size;
-	char buf[128];
-	char *ptr = buf;
-
-	while (*str == ' ' || *str == '\t')
-		str++;
-	if (!(*str))
-		return -EINVAL;
-	size = 1;	/* for '\0' */
-	if (*str != '"' && *str != '\'') {
-		while (*str && *str != ',') {
-			if (size < (int)sizeof(buf)) {
-				*ptr++ = *str;
-				size++;
-			}
-			str++;
-		}
-	} else {
-		c = *str++;
-		while (*str && *str != c) {
-			if (size < (int)sizeof(buf)) {
-				*ptr++ = *str;
-				size++;
-			}
-			str++;
-		}
-		if (*str == c)
-			str++;
-	}
-	if (*str == '\0') {
-		snd_mixer_selem_id_set_index(sid, 0);
-		*ptr = 0;
-		goto _set;
-	}
-	if (*str != ',')
-		return -EINVAL;
-	*ptr = 0;	/* terminate the string */
-	str++;
-	if (!isdigit(*str))
-		return -EINVAL;
-	snd_mixer_selem_id_set_index(sid, atoi(str));
-       _set:
-	snd_mixer_selem_id_set_name(sid, buf);
-	return 0;
-}
-
-int mixer_init (const char *name)
-{
-	/* from amixer.c, replaced -EINVAL with -1 */
-	int i, err;
-	if (!name)
-		name = "Master";
-
-	for (i = 0; i < num_mixers; i++) {
-		if (!strcasecmp (mixer_data[i].name, name)) {
-			return i;
-		}
-	}
-	if (i == MAX_MIXERS) {
-		fprintf (stderr, "max mixers (%d) reached\n", MAX_MIXERS);
-		return -1;
-	};
-
-	num_mixers++;
-#define data mixer_data[i]
-
-	strncpy (mixer_data[i].name, name, 63);
-	mixer_data[i].name[63] = '\0';
-	snd_mixer_selem_id_alloca (&data.sid);
-	data.mixer = NULL;
-	if (parse_simple_id (name, data.sid) < 0) {
-		fprintf (stderr, "Wrong mixer identifier: %s\n", name);
-		return -1;
-	}
-	if ((err = snd_mixer_open (&data.mixer, 0)) < 0) {
-		fprintf (stderr, "snd_mixer_open: %s\n", snd_strerror (err));
-		return -1;
-	}
-	if ((err = snd_mixer_attach (data.mixer, soundcard)) < 0) {
-		fprintf (stderr, "snd_mixer_attach: %s\n", snd_strerror (err));
-		return -1;
-	}
-	if ((err = snd_mixer_selem_register (data.mixer, NULL, NULL)) < 0) {
-		fprintf (stderr, "snd_mixer_selem_register: %s\n",
-			 snd_strerror (err));
-		return -1;
-	}
-	if ((err = snd_mixer_load (data.mixer)) < 0) {
-		fprintf (stderr, "snd_mixer_load: %s\n", snd_strerror (err));
-		return -1;
-	}
-	if (!(data.elem = snd_mixer_find_selem (data.mixer, data.sid))) {
-		fprintf (stderr, "snd_mixer_find_selem (\"%s\", %i)\n",
-			 snd_mixer_selem_id_get_name (data.sid),
-			 snd_mixer_selem_id_get_index (data.sid));
-		return -1;
-	}
-	snd_mixer_selem_get_playback_volume_range(data.elem, &data.vol_min, &data.vol_max);
-	return i;
-}
-static int mixer_get_avg (int i)
-{
-	long val;
-
-	snd_mixer_handle_events (data.mixer);
-	snd_mixer_selem_get_playback_volume (data.elem, 0, &val);
-	if(data.vol_max != 100) {
-		float avgf = ((float)val / data.vol_max) * 100;
-		int avg = (int)avgf;
-		return (avgf - avg < 0.5) ? avg : avg + 1;
-	}
-	return (int) val;
-}
-static int mixer_get_left (int i)
-{
-  /* stub */
-  return mixer_get_avg (i);
-}
-static int mixer_get_right (int i)
-{
-  /* stub */
-  return mixer_get_avg (i);
-}
-int mixer_to_255(int i, int x)
-{
-  return (x-data.vol_min)*255/(data.vol_max-data.vol_min);
-}
-int mixer_is_mute(int i)
-{
-	snd_mixer_handle_events (data.mixer);
-	if (snd_mixer_selem_has_playback_switch (data.elem)) {
-		int val, err;
-		if ((err = snd_mixer_selem_get_playback_switch(data.elem, 0, &val)) < 0)
-			fprintf (stderr, "playback_switch: %s\n", snd_strerror (err));
-		return !val;
-	} else {
-		return !mixer_get_avg(i);
-	}
-}
-#undef data
 
-#else /* MIXER_IS_ALSA */
 int mixer_init(const char *name)
 {
 	unsigned int i;
@@ -281,8 +117,7 @@ int mixer_is_mute(int i)
 	return !mixer_get(i);
 }
 
-#define mixer_to_255(i, x) x
-#endif /* MIXER_IS_ALSA */
+#define mixer_to_255(i, x) x * 2.55
 
 void parse_mixer_arg(struct text_object *obj, const char *arg)
 {
