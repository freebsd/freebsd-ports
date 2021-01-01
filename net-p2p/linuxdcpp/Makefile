# $FreeBSD$

PORTNAME=	linuxdcpp
PORTVERSION=	1.1.0
PORTREVISION=	17
CATEGORIES=	net-p2p
MASTER_SITES=	http://launchpadlibrarian.net/69733951/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of the DC++ Direct Connect client to Unix-like systems

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs

USES=		compiler:c++11-lang gettext gnome iconv localbase:ldflags \
		pkgconfig scons:python2 ssl tar:bzip2
USE_GNOME=	libglade2
INSTALLS_ICONS=	yes
PORTDOCS=	*
DESTDIRNAME=	FAKE_ROOT

OPTIONS_DEFINE=	NOTIFY DOCS
OPTIONS_DEFAULT=NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MAKE_ARGS_OFF=	libnotify=0

.if defined(WITH_DEBUG)
MAKE_ARGS+=	debug=1
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/'iconv'/'${ICONV_LIB:S/-l//}'/" \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|g++|${CXX}|' ${WRKSRC}/SConstruct

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
