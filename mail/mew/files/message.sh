#!/bin/sh
 
if [ -z "${SITE_STARTUP_FILE}" ]; then
    ${CAT} <<EOF > ${WRKTMPDIR}/MESSAGE
*************************************************************************
* You must set at least following elisps to your own dot.emacs file:    *
*                                                                       *
*       (autoload 'mew "mew" nil t)                                     *
*       (autoload 'mew-send "mew" nil t)                                *
*       (setq mew-mail-domain-list '("Name_Server_Domain_Name"))        *
*                                                                       *
*************************************************************************
EOF
else
    ${CAT} <<EOF > ${WRKTMPDIR}/MESSAGE
*************************************************************************
* You must set at least following elisps to your own dot.emacs file:    *
*                                                                       *
*       (require 'mew-${EMACS_PORT_NAME}-startup)                                  *
*       (autoload 'mew "mew" nil t)                                     *
*       (autoload 'mew-send "mew" nil t)                                *
*       (setq mew-mail-domain-list '("Name_Server_Domain_Name"))        *
*                                                                       *
*************************************************************************
EOF
fi    
