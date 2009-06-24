# New ports collection makefile for:    pinentry-gtk
# Date created:                         03 May 2004
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pinentry

COMMENT=	GTK version of the gnupg password dialog

CONFLICTS=	pinentry-[0-9]*

PINENTRY_SLAVE=	-gtk
WITH_GTK=	yes

MASTERDIR=	${.CURDIR}/../pinentry

.include "${MASTERDIR}/Makefile"
