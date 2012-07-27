# New ports collection makefile for:    pinentry-qt
# Date created:                         03 May 2004
# Whom:					Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pinentry

COMMENT=	QT3 version of the gnupg password dialog

CONFLICTS_INSTALL=	pinentry-[0-9]* pinentry-curses-* pinentry-gtk-* \
		pinentry-gtk2-* pinentry-qt4-*

PINENTRY_SLAVE=	-qt3
PORT_OPTIONS+=	QT3

MASTERDIR=	${.CURDIR}/../pinentry

.include "${MASTERDIR}/Makefile"
