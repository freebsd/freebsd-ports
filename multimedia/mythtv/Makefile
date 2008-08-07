#
# Ports collection makefile for:        mythtv
# Date created:                         05 February 2005
# Whom:                                 Stacey Son <mythdev@son.org>
#                                       Ari Maniatis <ari@ish.com.au>
#
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.20
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://chuggalug.clues.com/mythtv/
DISTNAME=	mythtv-fixes-0.20-13053

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-SAX-Expat
RUN_DEPENDS=	tv_check:${PORTSDIR}/textproc/p5-xmltv \
		${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin \
		wget:${PORTSDIR}/ftp/wget

BROKEN=		Incorrect handling of user addition
DEPRECATED=	Has been broken for more than 6 months
EXPIRATION_DATE=2008-09-19

ONLY_FOR_ARCHS= i386
USE_BZIP2=	yes
USE_QT_VER=	3
USE_MYSQL=	51
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" \
		CFLAGS="${CFLAGS}"
MAKE_ENV=	QTDIR="${QT_PREFIX}" QMAKESPEC="${QMAKESPEC}"
USE_RC_SUBR=	mythbackend

CONFIG=		--enable-xvmc --enable-opengl-vsync \
		--disable-xvmc-pro --disable-xvmc-vld --disable-xvmcw  \
		--prefix=${PREFIX} --extra-cflags=-g --extra-cxxflags=-g

CONFIGURE_ARGS=	--with-qt-dir=${LOCALBASE} ${CONFIG}

QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

OPTIONS=	LIRC	"Native LIRC Support" 	Off
OPTIONS+=       MYSQL_LOCAL "RUN_DEPEND on selected MySQL server" off

.include <bsd.port.pre.mk>

.if defined(WITH_LIRC)
LIB_DEPENDS+=  lirc_client.1:${PORTSDIR}/comms/lirc
# EXTRA_PATCHES= ${FILESDIR}/patchsettings-lirc
.endif

.if defined(WITH_MYSQL_LOCAL)
RUN_DEPENDS+=  mysqld:${PORTSDIR}/databases/${MYSQL_VER}-server
.endif

post-extract:
		${ECHO_CMD} 'const char *myth_source_version = "FreeBSD Ports Collection' \
			`pwd`, MythTV version ${PORTVERSION} "`date`\";" \
			> ${WRKSRC}/programs/mythfrontend/version.cpp
		${CP} -p ${WRKSRC}/programs/mythfrontend/version.cpp  ${WRKSRC}/programs/mythbackend
		${ECHO_CMD} export QMAKESPEC=${QMAKESPEC}

do-configure:
		@cd ${WRKSRC} && QMAKESPEC=${QMAKESPEC} ./configure ${CONFIG}
		@${ECHO_CMD} MAKE_ENV: ${MAKE_ENV}
		@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
			-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ mythtv.pro

post-install:
		${MKDIR} ${PREFIX}/share/mythtv/database
		${CP} ${WRKSRC}/database/mc.sql ${PREFIX}/share/mythtv/database
		${CP} ${WRKSRC}/programs/mythtv-setup/mythtv-setup ${PREFIX}/bin/mythtv-setup
		${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
		${MKDIR} ${PREFIX}/share/mythtv/database

.include <bsd.port.post.mk>
