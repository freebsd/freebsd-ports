# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-qt5

MASTERDIR=	${.CURDIR}/../android-file-transfer

CONFLICTS_INSTALL=	${PORTNAME}-qt4

OPTIONS_SLAVE=	QT5
OPTIONS_EXCLUDE=${OPTIONS_MULTI_COMP} ${OPTIONS_RADIO_GUI}

# XXX Why OPTIONS_EXCLUDE doesn't trigger _OFF helpers?
post-patch-QT5-on:	post-patch-CLI-off

.include "${MASTERDIR}/Makefile"
