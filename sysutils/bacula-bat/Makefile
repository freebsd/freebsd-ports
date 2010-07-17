# New ports collection makefile for:	bacula-bat
# Date created:				18 Sep 2007
# Whom:					Dan Langille <dan@langille.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
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

.include "${MASTERDIR}/Makefile"
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libbac.so.${PORTVERSION:R:R}) && exists(${LOCALBASE}/lib/libbaccfg.so.${PORTVERSION:R:R})
LIB_DEPENDS+=	bac.${PORTVERSION:R:R}:${PORTSDIR}/sysutils/bacula-client
PLIST_SUB+=	INDEP="@comment "

.elif exists(${LOCALBASE}/lib/libbac.so.1) || exists(${LOCALBASE}/lib/libbaccfg.so.1)
# To prevent build with old libraries
IGNORE=		please update sysutils/bacula-client first

.else
WITH_LIBS=	YES
PLIST_SUB+=	INDEP=""
.endif

pre-everything::
	@${ECHO_MSG} "===> Building bat the GUI interface for Bacula."

do-install:
	# Install config files and preserve existing ones
	${INSTALL_SCRIPT}  ${WRKSRC}/src/qt-console/bat.conf ${PREFIX}/etc/bat.conf.sample
	${INSTALL_MAN}     ${WRKSRC}/manpages/bat.1          ${PREFIX}/man/man1/
.if defined(WITH_LIBS)
	${INSTALL_PROGRAM} ${WRKSRC}/src/qt-console/.libs/bat ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/lib/.libs/libbac.so.${PORTVERSION:R:R} \
	    ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/src/lib/.libs/libbaccfg.so.${PORTVERSION:R:R} \
	    ${PREFIX}/lib
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/qt-console/bat ${PREFIX}/sbin
.endif

.include <bsd.port.post.mk>
