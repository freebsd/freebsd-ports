#!/bin/sh
 
case ${EMACS_PORT_NAME} in
    emacs20)
	cat <<EOF > ${WRKTMPDIR}/pkg-message
*************************************************************************
* You must set at least following elisps to your own dot.emacs file:    *
*                                                                       *
*       (autoload 'mew "mew" nil t)                                     *
*       (autoload 'mew-send "mew" nil t)                                *
*       (setq mew-mail-domain "domain of e-mail address")               *
*       (setq mew-pop-server "your POP server")    ;; if not localhost  *
*       (setq mew-smtp-server "your SMTP server")  ;; if not localhost  *
*       (setq mew-prog-pgpkey      "fetch")         ;; for PGP use      *
*       (setq mew-prog-pgpkey-arg  '("-q" "-o" "-"));; for PGP use      *
*                                                                       *
*************************************************************************
EOF
	;;
    xemacs21*)
	cat <<EOF > ${WRKTMPDIR}/pkg-message
*************************************************************************
* You must set at least following elisps to your own dot.emacs file:    *
*                                                                       *
*       (autoload 'mew "mew" nil t)                                     *
*       (autoload 'mew-send "mew" nil t)                                *
*       (setq mew-mail-domain "domain of e-mail address")               *
*       (setq mew-pop-server "your POP server")    ;; if not localhost  *
*       (setq mew-smtp-server "your SMTP server")  ;; if not localhost  *
*       (setq mew-icon-directory "icon directory") ;; if using XEmacs   *
*       (setq mew-prog-pgpkey      "fetch")         ;; for PGP use      *
*       (setq mew-prog-pgpkey-arg  '("-q" "-o" "-"));; for PGP use      *
*                                                                       *
*************************************************************************
EOF
	;;
esac
