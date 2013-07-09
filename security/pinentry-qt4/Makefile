# $FreeBSD$

PORTNAME=	pinentry
PORTREVISION=	3

COMMENT=	Qt 4 version of the gnupg password dialog

CONFLICTS_INSTALL=	pinentry-[0-9]* pinentry-curses-* pinentry-gtk-* \
		pinentry-gtk2-* pinentry-qt-*

PINENTRY_SLAVE=	-qt4
PORT_OPTIONS+=	QT4

MASTERDIR=	${.CURDIR}/../pinentry

.include "${MASTERDIR}/Makefile"
