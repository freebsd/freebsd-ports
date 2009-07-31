#
# Ports collection makefile for:        mythtv
# Date created:                         05 February 2005
# Whom:                                 Stacey Son <mythdev@son.org>
#                                       Ari Maniatis <ari@ish.com.au>
#
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.21
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.osuosl.org/pub/mythtv/ \
		LOCAL/glarkin

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-SAX-Expat
RUN_DEPENDS=	tv_check:${PORTSDIR}/textproc/p5-xmltv \
		${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin \
		wget:${PORTSDIR}/ftp/wget

ONLY_FOR_ARCHS= i386 amd64
USE_BZIP2=	yes
USE_QT_VER=	3
USE_MYSQL=	51
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LOCALE_CLEANUP= LANG="" LC_ALL="" LC_COLLATE="" LC_CTYPE="" \
		LC_MESSAGES="" LC_MONETARY="" LC_NUMERIC="" \
		LC_TIME=""
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" \
		CFLAGS="${CFLAGS}" ${LOCALE_CLEANUP}
MAKE_ENV=	QTDIR="${QT_PREFIX}" QMAKESPEC="${QMAKESPEC}" \
		${LOCALE_CLEANUP}
USE_RC_SUBR=	mythbackend
USE_LDCONFIG=	${PREFIX}/lib/mythtv/filters

CONFLICTS=	mythtv-frontend-[0-9]* mythtv-themes-[0-9]*

MYTHTVUSER?=	mythtv
MYTHTVGROUP?=	mythtv
MYTHTVUID?=	119
MYTHTVGID?=	${MYTHTVUID}
MYTHTVDIR?=	/nonexistent

CONFIG=		--enable-xvmc --enable-opengl-vsync --disable-directfb \
		--disable-ivtv \
		--disable-xvmc-pro --disable-xvmc-vld --disable-xvmcw  \
		--prefix=${PREFIX} --extra-cflags=-g --extra-cxxflags=-g

CONFIGURE_ARGS=	--with-qt-dir=${LOCALBASE} ${CONFIG}

QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

OPTIONS=	LIRC		"Native LIRC Support" Off \
		MYSQL_LOCAL	"RUN_DEPEND on selected MySQL server" Off

.include <bsd.port.pre.mk>

SUB_LIST=	MYTHTVDIR=${MYTHTVDIR} \
		MYTHTVUSER=${MYTHTVUSER} \
		MYTHTVGROUP=${MYTHTVGROUP} \
		MYTHTVUID=${MYTHTVUID} \
		MYTHTVGID=${MYTHTVGID} \
		PREFIX=${PREFIX} DATADIR=${DATADIR} \
		PW=${PW}

SUB_FILES=	pkg-install pkg-deinstall pkg-message

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
# EXTRA_PATCHES= ${FILESDIR}/patchsettings-lirc
.endif

.if defined(WITH_MYSQL_LOCAL)
RUN_DEPENDS+=	mysqld_safe:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
.endif

post-extract:
		@${ECHO_CMD} export QMAKESPEC=${QMAKESPEC}

do-configure:
		@${ECHO_CMD} CONFIGURE_ENV: ${CONFIGURE_ENV}
		@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
			./configure ${CONFIG}
		@${ECHO_CMD} MAKE_ENV: ${MAKE_ENV}
		@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
			-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
			mythtv.pro

post-install:
		@${INSTALL} -d ${PREFIX}/share/mythtv/database
		@${CP} ${WRKSRC}/database/mc.sql ${PREFIX}/share/mythtv/database
		@${CP} ${WRKSRC}/programs/mythtv-setup/mythtv-setup ${PREFIX}/bin/mythtv-setup
		@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
