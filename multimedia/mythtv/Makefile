# Created by: Stacey Son <mythdev@son.org>, Ari Maniatis <ari@ish.com.au>
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.27.5.20150616
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	MythTV is a homebrew PVR project

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libfreetype.so:print/freetype2 \
		libtag.so:audio/taglib \
		libxml2.so:textproc/libxml2
BUILD_DEPENDS=	v4l_compat>=1.0.20100321:multimedia/v4l_compat \
		yasm:devel/yasm
RUN_DEPENDS=	tv_check:textproc/p5-xmltv \
		wget:ftp/wget

CONFLICTS=	mythtv-frontend-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_TAGNAME=	ad97d24

WRKSRC_SUBDIR=	${PORTNAME}

ONLY_FOR_ARCHS=	i386 amd64
USE_PERL5=	run build
NOPRECIOUSMAKEVARS=	# don't override $(ARCH) in ffmpeg makefiles
USES=		gmake libtool perl5 pkgconfig pathfix shebangfix
SHEBANG_FILES=	programs/scripts/database/mythconverg_backup.pl \
		programs/scripts/database/mythconverg_restore.pl
USE_QT4=	gui sql network script linguist_build l10n sql-mysql_run \
		moc_build qmake_build rcc_build uic_build imageformats
QT_NONSTANDARD=	yes
USE_MYSQL=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mythtv/filters
REINPLACE_ARGS=	-i ""
USE_RC_SUBR=	mythbackend
DESTDIRNAME=	INSTALL_ROOT

USERS=		mythtv
GROUPS=		mythtv

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"

CPPFLAGS+=	${QTCPPFLAGS}
CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" \
		QTDIR="${QT_PREFIX}"
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}" --cxx="${CXX}" --dvb-path="${LOCALBASE}/include" \
		--libxml2-path="${LOCALBASE}/include/libxml2" --enable-v4l2 --enable-ivtv --enable-xv \
		--disable-audio-alsa --disable-indev=alsa --disable-outdev=alsa --disable-mythlogserver

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

OPTIONS_DEFINE=	BINDINGS LIRC MYSQL OPENGL VDPAU
OPTIONS_DEFAULT=	BINDINGS OPENGL VDPAU
OPTIONS_SUB=	BINDINGS
BINDINGS_DESC=	Perl and Python bindings

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
MYSQL_RUN_DEPENDS=	mysqld_safe:databases/mysql${MYSQL_VER}-server

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

OPENGL_CONFIGURE_ENABLE=	opengl-video

.include <bsd.port.options.mk>

SUB_FILES=	pkg-message

.if ${PORT_OPTIONS:MBINDINGS}
CONFIGURE_ARGS+=	--python=${PYTHON_CMD}
USES+=		python
PYDISTUTILS_PKGNAME=MythTV
PYDISTUTILS_PKGVERSION=0.27._1

BUILD_DEPENDS+=	py*-lxml>=0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb \
		${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.1.0_1:www/py-urlgrabber \
		p5-HTTP-Request-Params>=0:www/p5-HTTP-Request-Params \
		p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined \
		p5-Net-UPnP>=0:multimedia/p5-Net-UPnP \
		p5-IO-Socket-INET6>=2.51:net/p5-IO-Socket-INET6 \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>0:databases/p5-DBD-mysql
RUN_DEPENDS+=	py*-lxml>=0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb \
		${PYTHON_PKGNAMEPREFIX}urlgrabber>=3.1.0_1:www/py-urlgrabber \
		p5-HTTP-Request-Params>=0:www/p5-HTTP-Request-Params \
		p5-LWP-UserAgent-Determined>=0:www/p5-LWP-UserAgent-Determined \
		p5-Net-UPnP>=0:multimedia/p5-Net-UPnP \
		p5-IO-Socket-INET6>=2.51:net/p5-IO-Socket-INET6 \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>0:databases/p5-DBD-mysql
.else
CONFIGURE_ARGS+=--without-bindings=perl,python
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_QT4+=	opengl
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
		@${INSTALL} -d ${STAGEDIR}${PREFIX}/share/mythtv/database
		@${CP} ${WRKSRC}/database/mc.sql ${STAGEDIR}${PREFIX}/share/mythtv/database

.include <bsd.port.mk>
