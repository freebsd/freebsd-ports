#
# Ports collection makefile for:        mythtv
# Date created:                         05 February 2005
# Whom:                                 Stacey Son <mythdev@son.org>
#                                       Ari Maniatis <ari@ish.com.au>
#
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.22
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.osuosl.org/pub/mythtv/ \
		LOCAL/glarkin

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-SAX-Expat
RUN_DEPENDS=	tv_check:${PORTSDIR}/textproc/p5-xmltv \
		${QT_PREFIX}/lib/qt4/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin \
		wget:${PORTSDIR}/ftp/wget

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui sql network script linguist_build l10n \
		moc_build qmake_build rcc_build uic_build
USE_MYSQL=	51
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
USE_PERL=	yes
USE_PYTHON=	yes
INSTALLS_EGGINFO=yes
PYDISTUTILS_PKGNAME=MythTV
REINPLACE_ARGS=	-i ""

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" CPPFLAGS="${CPPFLAGS}  ${QTCPPFLAGS}" \
		QTDIR="${QT_PREFIX}" LDFLAGS="-L${LOCALBASE}/lib"

USE_RC_SUBR=	mythbackend
USE_LDCONFIG=	${PREFIX}/lib/mythtv/filters

CONFLICTS=	mythtv-frontend-[0-9]* mythtv-themes-[0-9]*

MYTHTVUSER?=	mythtv
MYTHTVGROUP?=	mythtv
MYTHTVUID?=	119
MYTHTVGID?=	${MYTHTVUID}
MYTHTVDIR?=	/nonexistent

CONFIGURE_ARGS=	--enable-xvmc --enable-opengl-vsync --disable-directfb --enable-ivtv \
		--disable-xvmc-pro --disable-xvmc-vld --disable-xvmcw \
		--prefix=${PREFIX} --extra-cflags=-g --extra-cxxflags=-g

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

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

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			${WRKSRC}/libs/libmythtv/libmythtv.pro \
			${WRKSRC}/libs/libavformat/libavformat.pro \
			${WRKSRC}/bindings/perl/MythTV/Recording.pm \
			${WRKSRC}/programs/mythtranscode/replex/Makefile.standalone \
			${WRKSRC}/programs/scripts/database/mythconverg_backup.pl

post-install:
		@${INSTALL} -d ${PREFIX}/share/mythtv/database
		@${CP} ${WRKSRC}/database/mc.sql ${PREFIX}/share/mythtv/database
		@${CP} ${WRKSRC}/programs/mythtv-setup/mythtv-setup ${PREFIX}/bin/mythtv-setup
		@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
