#!/bin/sh
 
if [ -z "${EMACS_SETUPEL}" ]; then
    cat <<EOF > ${WRKTMPDIR}/pkg-message
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
    cat <<EOF > ${WRKTMPDIR}/pkg-message
*************************************************************************
* You must set at least following elisps to your own dot.emacs file:    *
*                                                                       *
*       (require '`basename ${EMACS_SETUPEL} .el`)                                  *
*       (autoload 'mew "mew" nil t)                                     *
*       (autoload 'mew-send "mew" nil t)                                *
*       (setq mew-mail-domain-list '("Name_Server_Domain_Name"))        *
*                                                                       *
*************************************************************************
EOF
fi    
