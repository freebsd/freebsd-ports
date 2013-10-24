# $FreeBSD$

PORTNAME=	linuxdcpp
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://launchpadlibrarian.net/69733951/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of the DC++ Direct Connect client to Unix-like systems

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GNOME=	libglade2
USES=		iconv pkgconfig scons
USE_OPENSSL=	yes
PORTDOCS=	*
DESTDIRNAME=	FAKE_ROOT

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.if defined(WITH_DEBUG)
MAKE_ARGS+=	debug=1
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
.else
MAKE_ARGS+=	libnotify=0
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/'iconv'/'${ICONV_LIB:S/-l//}'/" \
		${WRKSRC}/SConstruct

.include <bsd.port.mk>
