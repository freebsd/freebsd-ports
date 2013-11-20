#!/bin/sh

plugin_srcs="attachment-reminder/attachment-reminder.c bbdb/bbdb.c dbx-import/dbx-importer.c email-custom-header/email-custom-header.c external-editor/external-editor.c face/face.c image-inline/image-inline.c mail-notification/mail-notification.c mail-to-task/mail-to-task.c mailing-list-actions/mailing-list-actions.c mark-all-read/mark-all-read.c pst-import/pst-importer.c publish-calendar/publish-calendar.c save-calendar/save-calendar.c templates/templates.c"

module_srcs="addressbook/evolution-module-addressbook.c audio-inline/evolution-module-audio-inline.c backup-restore/evolution-backup-tool.c bogofilter/evolution-bogofilter.c book-config-google/evolution-book-config-google.c book-config-ldap/evolution-book-config-ldap.c book-config-local/evolution-book-config-local.c book-config-webdav/evolution-book-config-webdav.c cal-config-caldav/evolution-cal-config-caldav.c cal-config-contacts/evolution-cal-config-contacts.c cal-config-google/evolution-cal-config-google.c cal-config-local/evolution-cal-config-local.c cal-config-weather/evolution-cal-config-weather.c cal-config-webcal/evolution-cal-config-webcal.c calendar/evolution-module-calendar.c composer-autosave/evolution-composer-autosave.c imap-features/evolution-imap-features.c itip-formatter/itip-view.c itip-formatter/plugin/config-ui.c mail-config/evolution-mail-config.c mail/evolution-module-mail.c mailto-handler/evolution-mailto-handler.c mdn/evolution-mdn.c offline-alert/evolution-offline-alert.c online-accounts/evolution-online-accounts.c plugin-lib/evolution-module-plugin-lib.c plugin-manager/evolution-plugin-manager.c prefer-plain/evolution-module-prefer-plain.c prefer-plain/plugin/config-ui.c spamassassin/evolution-spamassassin.c startup-wizard/evolution-startup-wizard.c text-highlight/languages.c tnef-attachment/evolution-module-tnef-attachment.c vcard-inline/evolution-module-vcard-inline.c web-inspector/evolution-web-inspector.c"

WRKSRC=$1

for i in ${plugin_srcs}; do
    if [ ! -f ${WRKSRC}/plugins/${i} ]; then
	echo "WARNING: Failed to find plugin source file ${WRKSRC}/plugins/${i}"
	continue
    fi
    cp ${WRKSRC}/plugins/${i} ${WRKSRC}/plugins/${i}.bak
    printf "const char * g_module_check_init (gpointer module);\n" >> ${WRKSRC}/plugins/${i}
    printf "const char *\ng_module_check_init (gpointer module) {\n\treturn NULL;\n}\n" >> ${WRKSRC}/plugins/${i}
    printf "void g_module_unload (gpointer module);\n" >> ${WRKSRC}/plugins/${i}
    printf "void\ng_module_unload (gpointer module) {\n\treturn;\n}\n" >> ${WRKSRC}/plugins/${i}
    dir=$(dirname ${WRKSRC}/plugins/${i})
    if ! grep -q e_plugin_lib_enable ${dir}/*.c; then
	printf "#include <e-util/e-config.h>\n" >> ${WRKSRC}/plugins/${i}
	printf "gint e_plugin_lib_enable (EPlugin *ep, gint enable);\n" >> ${WRKSRC}/plugins/${i}
	printf "gint\ne_plugin_lib_enable (EPlugin *ep, gint enable) {\n\treturn 0;\n}\n" >> ${WRKSRC}/plugins/${i}
    fi
    if ! grep -q e_plugin_lib_get_configure_widget ${dir}/*.c; then
	printf "#include <e-util/e-config.h>\n" >> ${WRKSRC}/plugins/${i}
	printf "GtkWidget *e_plugin_lib_get_configure_widget (EPlugin *plugin);\n" >> ${WRKSRC}/plugins/${i}
	printf "GtkWidget *\ne_plugin_lib_get_configure_widget (EPlugin *plugin) {\n\treturn NULL;\n}" >> ${WRKSRC}/plugins/${i}
    fi
done

for i in ${module_srcs}; do
    if [ ! -f ${WRKSRC}/modules/${i} ]; then
	echo "WARNING: Failed to find module source file ${WRKSRC}/modules/${i}"
	continue
    fi
    cp ${WRKSRC}/modules/${i} ${WRKSRC}/modules/${i}.bak
    dir=$(dirname ${WRKSRC}/modules/${i})
    if ! grep -q g_module_check_init ${dir}/*.c; then
        printf "const char * g_module_check_init (gpointer module);\n" >> ${WRKSRC}/modules/${i}
        printf "const char *\ng_module_check_init (gpointer module) {\n\treturn NULL;\n}\n" >> ${WRKSRC}/modules/${i}
    fi
    if ! grep g_module_unload ${dir}/*.c; then
        printf "void g_module_unload (gpointer module);\n" >> ${WRKSRC}/modules/${i}
        printf "void\ng_module_unload (gpointer module) {\n\treturn;\n}\n" >> ${WRKSRC}/modules/${i}
    fi
done

