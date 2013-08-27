# Created by: Stacey Son <mythdev@son.org>, Ari Maniatis <ari@ish.com.au>
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.26.1
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.osuosl.org/pub/mythtv/old_releases/ \
		http://ftp.oregonstate.edu/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/old_releases/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		freetype.9:${PORTSDIR}/print/freetype2 \
		tag.1:${PORTSDIR}/audio/taglib
BUILD_DEPENDS=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat \
		yasm:${PORTSDIR}/devel/yasm
RUN_DEPENDS=	tv_check:${PORTSDIR}/textproc/p5-xmltv \
		wget:${PORTSDIR}/ftp/wget

CONFLICTS=	mythtv-frontend-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USES=		pkgconfig
USE_BZIP2=	yes
USE_QT4=	gui sql network script linguist_build l10n sql-mysql_run \
		moc_build qmake_build rcc_build uic_build imageformats
QT_NONSTANDARD=	yes
USE_MYSQL=	51
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_PERL5=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/filters
REINPLACE_ARGS=	-i ""
USE_RC_SUBR=	mythbackend

USERS=		mythtv
GROUPS=		mythtv

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CPPFLAGS+=	${QTCPPFLAGS}
CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" \
		QTDIR="${QT_PREFIX}"
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--prefix="${PREFIX}" --dvb-path="${LOCALBASE}/include" \
		--enable-v4l2 --enable-ivtv --enable-xv \
		--disable-audio-alsa --disable-indev=alsa --disable-outdev=alsa

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

OPTIONS_DEFINE=	BINDINGS LIRC MYSQL OPENGL VDPAU
OPTIONS_DEFAULT=	BINDINGS OPENGL
BINDINGS_DESC=	Perl and Python bindings

.include <bsd.port.options.mk>

SUB_FILES=	pkg-message

# for too old binutils in base
.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${PORT_OPTIONS:MBINDINGS}
USE_PYTHON=	yes
INSTALLS_EGGINFO=yes
PYDISTUTILS_PKGNAME=MythTV
PYDISTUTILS_PKGVERSION=0.26.0

BUILD_DEPENDS+=	py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb \
		${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.1.0_1:${PORTSDIR}/www/py-urlgrabber \
		p5-HTTP-Request-Params>=0:${PORTSDIR}/www/p5-HTTP-Request-Params \
		p5-LWP-UserAgent-Determined>=0:${PORTSDIR}/www/p5-LWP-UserAgent-Determined \
		p5-Net-UPnP>=0:${PORTSDIR}/multimedia/p5-Net-UPnP \
		p5-IO-Socket-INET6>=2.51:${PORTSDIR}/net/p5-IO-Socket-INET6
RUN_DEPENDS+=	py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb \
		${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.1.0_1:${PORTSDIR}/www/py-urlgrabber \
		p5-HTTP-Request-Params>=0:${PORTSDIR}/www/p5-HTTP-Request-Params \
		p5-LWP-UserAgent-Determined>=0:${PORTSDIR}/www/p5-LWP-UserAgent-Determined \
		p5-Net-UPnP>=0:${PORTSDIR}/multimedia/p5-Net-UPnP \
		p5-IO-Socket-INET6>=2.51:${PORTSDIR}/net/p5-IO-Socket-INET6
PLIST_SUB+=	BINDINGS=""
.else
CONFIGURE_ARGS+=--without-bindings=perl,python
PLIST_SUB+=	BINDINGS="@comment "
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	lirc_client.2:${PORTSDIR}/comms/lirc
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	mysqld_safe:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_QT4+=	opengl
CONFIGURE_ARGS+=	--enable-opengl-video
.else
CONFIGURE_ARGS+=	--disable-opengl-video
.endif

.if ${PORT_OPTIONS:MVDPAU}
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
