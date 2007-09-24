# New ports collection makefile for:	bacula-bat
# Date created:				18 Sep 2007
# Whom:					Dan Langille <dan@langille.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
PKGNAMESUFFIX=  -bat

COMMENT=	The network backup solution (GUI)

WITH_BAT=	yes

USE_QT_VER=	4
QT_COMPONENTS=	qmake
pre-install:
# override master

post-install:
# override master

do-install:
# 	Install config files and preserve existing ones
	${INSTALL_PROGRAM} ${WRKSRC}/src/qt-console/bat      ${PREFIX}/sbin
	${INSTALL_SCRIPT}  ${WRKSRC}/src/qt-console/bat.conf ${PREFIX}/etc/bat.conf.sample
	${INSTALL_MAN}     ${WRKSRC}/manpages/bat.1          ${PREFIX}/man/man1/bat.1.gz

MAN1=bat.1

MAKE_ARGS=	-E MAN1
MAKE_ENV=	MAN1="${MAN1}"

MAKE_ENV+=	MAKEOBJDIRPREFIX=/

LIB_DEPENDS+= qwt.5:${PORTSDIR}/x11-toolkits/qwt-devel

PLIST=${.CURDIR}/pkg-plist

CONFIGURE_ARGS+=	--enable-bat \
			--with-qwt={$PREFIX}/lib \
			--disable-build-dird \
			--disable-build-stored \
			--enable-client-only

MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server
.include "${MASTERDIR}/Makefile"
