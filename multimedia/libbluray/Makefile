# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libbluray
PORTVERSION=	0.5.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Blu-Ray discs playback library for media players

LICENSE=	LGPL21

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
# dlopen dependencies, libbdplus not yet available
LIB_DEPENDS+=	libaacs.so:${PORTSDIR}/multimedia/libaacs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

OPTIONS_DEFINE=	JAVA
OPTIONS_SUB=	yes
JAVA_DESC=	Enable Blu-Ray Java support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
CATEGORIES+=	java
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_BUILD=	yes
JAVA_RUN=	yes
CONFIGURE_ARGS+=	--enable-bdjava --with-bdj-type=j2se
CONFIGURE_ENV+=	JDK_HOME="${JAVA_HOME}"
.endif

post-patch:
	@${REINPLACE_CMD} '/^SET_FEATURES =/d' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
