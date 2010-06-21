#
# Ports collection makefile for:        mythtv
# Date created:                         05 February 2005
# Whom:                                 Stacey Son <mythdev@son.org>
#                                       Ari Maniatis <ari@ish.com.au>
#
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.23
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-SAX-Expat
RUN_DEPENDS=	tv_check:${PORTSDIR}/textproc/p5-xmltv \
		${QT_PREFIX}/lib/qt4/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin \
		wget:${PORTSDIR}/ftp/wget

CONFLICTS=	mythtv-frontend-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui sql network script linguist_build l10n \
		moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
USE_MYSQL=	51
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_PERL=	yes
USE_PYTHON=	yes
INSTALLS_EGGINFO=yes
PYDISTUTILS_PKGNAME=MythTV
PYDISTUTILS_PKGVERSION=${PORTVERSION}.0
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
		--enable-ivtv --enable-xvmc --disable-xvmcw --disable-xvmc-pro \
		--disable-directfb --enable-glx-procaddrarb

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

OPTIONS=	LIRC		"Native LIRC Support" off \
		MYSQL_LOCAL	"RUN_DEPEND on selected MySQL server" off \
		OPENGL		"OpenGL support" on \
		VDPAU		"VDPAU support (nvidia only)" off

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
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
LIB_DEPENDS+=	vdpau.1:${PORTSDIR}/x11/nvidia-driver
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			${WRKSRC}/configure \
			${WRKSRC}/libs/libmythtv/libmythtv.pro \
			${WRKSRC}/libs/libavformat/libavformat.pro \
			${WRKSRC}/bindings/perl/MythTV/Recording.pm \
			${WRKSRC}/programs/mythtranscode/replex/Makefile.standalone \
			${WRKSRC}/programs/scripts/database/mythconverg_backup.pl \
			${WRKSRC}/programs/scripts/database/mythconverg_restore.pl \
			${WRKSRC}/contrib/encoding_converting/mythencode/mythencode.pl \
			${WRKSRC}/contrib/user_jobs/firewire_primer.pl \
			${WRKSRC}/contrib/user_jobs/mythvidexport.py \
			${WRKSRC}/contrib/info/mythname/mythname.pl \
			${WRKSRC}/programs/mythcommflag/mythcommflag-analyze

post-install:
		@${INSTALL} -d ${PREFIX}/share/mythtv/database
		@${CP} ${WRKSRC}/database/mc.sql ${PREFIX}/share/mythtv/database
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
