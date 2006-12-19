#
# Ports collection makefile for:        mythtv
# Date created:                         05 February 2005
# Whom:                                 Stacey Son <mythdev@son.org>
#                                       Ari Maniatis <ari@ish.com.au>   
#
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.20
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mythtv.org/mc/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	myth4fbsd@son.org
COMMENT=	MythTV is a homebrew PVR project

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		${X11BASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2

RUN_DEPENDS=	tv_check:${PORTSDIR}/textproc/p5-xmltv \
		wget:${PORTSDIR}/ftp/wget \
		mysql:${PORTSDIR}/databases/mysql51-server

USE_BZIP2=	yes
USE_QT_VER=	3
USE_MYSQL=	40
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${LOCALBASE}" \
		QMAKESPEC="${QMAKESPEC}" \
		CFLAGS="${CFLAGS}"
MAKE_ENV=	QTDIR="${X11BASE}" QMAKESPEC="${QMAKESPEC}"
USE_RC_SUBR=	yes

CONFIGURE_ARGS=	--with-qt-dir=${LOCALBASE}
# CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

OPTIONS=	LIRC	"Native LIRC Support" 	Off

.include <bsd.port.pre.mk>

.if defined(WITH_LIRC)
LIB_DEPENDS+=  lirc_client.0:${PORTSDIR}/comms/lirc
# EXTRA_PATCHES= ${FILESDIR}/patchsettings-lirc
.endif

post-extract:
		@${SED} "s|%%RC_SUBR%%|${RC_SUBR}|g;s|%%PREFIX%%|${PREFIX}|g" \
		${FILESDIR}/mythbackend.sh > ${WRKSRC}/mythbackend.sh
		echo 'const char *myth_source_version = "FreeBSD Ports Collection' \
			`pwd`, MythTV version ${PORTVERSION} "`date`\";" \
			> ${WRKSRC}/programs/mythfrontend/version.cpp
		cp -p ${WRKSRC}/programs/mythfrontend/version.cpp  ${WRKSRC}/programs/mythbackend
		echo export QMAKESPEC=${QMAKESPEC}

do-configure:
		@cd ${WRKSRC} && QMAKESPEC=${QMAKESPEC} \
			./configure --enable-memalign-hack --prefix=${PREFIX} \
			--extra-cflags=-g --extra-cxxflags=-g
		@echo MAKE_ENV: ${MAKE_ENV}
		@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
			-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ mythtv.pro

post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/mythbackend.sh ${PREFIX}/etc/rc.d/mythbackend.sh
		${MKDIR} ${PREFIX}/share/mythtv/database
		${CP} ${WRKSRC}/database/mc.sql ${PREFIX}/share/mythtv/database
		${CP} ${WRKSRC}/programs/mythtv-setup/mythtv-setup ${PREFIX}/bin/mythtv-setup
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
