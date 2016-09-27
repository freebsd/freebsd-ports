# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-qt4

MASTERDIR=	${.CURDIR}/../android-file-transfer

CONFLICTS_INSTALL=	${PORTNAME}-qt5

OPTIONS_SLAVE=	QT4
OPTIONS_EXCLUDE=${OPTIONS_MULTI_COMP} ${OPTIONS_RADIO_GUI}

# XXX Why OPTIONS_EXCLUDE doesn't trigger _OFF helpers?
post-patch-QT4-on:	post-patch-CLI-off

.include "${MASTERDIR}/Makefile"
