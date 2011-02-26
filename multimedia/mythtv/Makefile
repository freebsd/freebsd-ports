#
# Ports collection makefile for:        mythtv
# Date created:                         05 February 2005
# Whom:                                 Stacey Son <mythdev@son.org>
#                                       Ari Maniatis <ari@ish.com.au>
#
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.24
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.osuosl.org/pub/mythtv/old_releases/ \
		http://ftp.oregonstate.edu/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/old_releases/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat
RUN_DEPENDS=	tv_check:${PORTSDIR}/textproc/p5-xmltv \
		wget:${PORTSDIR}/ftp/wget

CONFLICTS=	mythtv-frontend-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui sql network script linguist_build l10n sql-mysql_run \
		moc_build qmake_build rcc_build uic_build imageformats
QT_NONSTANDARD=	yes
USE_MYSQL=	51
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_PERL=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/filters
REINPLACE_ARGS=	-i ""
USE_RC_SUBR=	mythbackend

USERS=		mythtv
GROUPS=		mythtv

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" CPPFLAGS="${CPPFLAGS} ${QTCPPFLAGS}" \
		QTDIR="${QT_PREFIX}" LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--prefix=${PREFIX} --dvb-path=${LOCALBASE}/include \
		--extra-cflags=-g --extra-cxxflags=-g --enable-v4l \
		--enable-ivtv --enable-xvmc --disable-xvmcw \
		--disable-directfb --disable-audio-alsa

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

OPTIONS=	BINDINGS	"Perl and Python bindings" off \
		LIRC		"Native LIRC Support" off \
		MYSQL_LOCAL	"RUN_DEPEND on selected MySQL server" off \
		OPENGL		"OpenGL support" on \
		VDPAU		"VDPAU support (nvidia only)" off

.include <bsd.port.options.mk>

SUB_FILES=	pkg-message

.if defined(WITH_BINDINGS)
USE_PYTHON=	yes
INSTALLS_EGGINFO=yes
PYDISTUTILS_PKGNAME=MythTV
PYDISTUTILS_PKGVERSION=${PORTVERSION}.0

BUILD_DEPENDS+=	py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
RUN_DEPENDS+=	py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
CONFIGURE_ARGS+=--without-bindings=perl
PLIST_SUB+=	BINDINGS=""
.else
CONFIGURE_ARGS+=--without-bindings=perl,python
PLIST_SUB+=	BINDINGS="@comment "
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.2:${PORTSDIR}/comms/lirc
.endif

.if defined(WITH_MYSQL_LOCAL)
RUN_DEPENDS+=	mysqld_safe:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
.endif

.if defined(WITH_OPENGL)
QT_COMPONENTS+=	opengl
CONFIGURE_ARGS+=	--enable-opengl-video --enable-opengl-vsync
.else
CONFIGURE_ARGS+=	--disable-opengl-video --disable-opengl-vsync
.endif

.if defined(WITH_VDPAU)
LIB_DEPENDS+=	vdpau.1:${PORTSDIR}/multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			${WRKSRC}/configure \
			${WRKSRC}/libs/libmythtv/libmythtv.pro \
			${WRKSRC}/bindings/perl/MythTV/Recording.pm \
			${WRKSRC}/programs/mythtranscode/replex/Makefile.standalone \
			${WRKSRC}/programs/scripts/database/mythconverg_backup.pl \
			${WRKSRC}/programs/scripts/database/mythconverg_restore.pl \
			${WRKSRC}/programs/mythcommflag/mythcommflag-analyze

post-install:
		@${INSTALL} -d ${PREFIX}/share/mythtv/database
		@${CP} ${WRKSRC}/database/mc.sql ${PREFIX}/share/mythtv/database
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
