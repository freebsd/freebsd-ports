# New ports collection makefile for:	bacula-bat
# Date created:				18 Sep 2007
# Whom:					Dan Langille <dan@langille.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
PORTREVISION=	2
PKGNAMESUFFIX=	-bat

COMMENT=	The network backup solution (GUI)

LIB_DEPENDS+=	qwt.5:${PORTSDIR}/x11-toolkits/qwt5

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build
WITH_BAT=	yes

MAN1=		bat.1

MAKE_ARGS=	-E MAN1
MAKE_ENV+=	MAKEOBJDIRPREFIX=/

MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

PLIST=		${.CURDIR}/pkg-plist

CONFIGURE_ARGS+=--enable-bat \
		--with-qwt=${LOCALBASE}/lib \
		--disable-build-dird \
		--disable-build-stored \
		--enable-client-only

pre-install:
	# override master

post-install:
	# override master

do-install:
	# Install config files and preserve existing ones
	${INSTALL_PROGRAM} ${WRKSRC}/src/qt-console/.libs/bat ${PREFIX}/sbin
	${INSTALL_SCRIPT}  ${WRKSRC}/src/qt-console/bat.conf ${PREFIX}/etc/bat.conf.sample
	${GZIP_CMD} ${WRKSRC}/manpages/bat.1
	${INSTALL_MAN}     ${WRKSRC}/manpages/bat.1.gz          ${PREFIX}/man/man1/

.include "${MASTERDIR}/Makefile"
