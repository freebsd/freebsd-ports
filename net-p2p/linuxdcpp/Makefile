# $FreeBSD$

PORTNAME=	linuxdcpp
PORTVERSION=	1.1.0
PORTREVISION=	16
CATEGORIES=	net-p2p
MASTER_SITES=	http://launchpadlibrarian.net/69733951/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of the DC++ Direct Connect client to Unix-like systems

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs

USES=		compiler:c++11-lang gettext gnome iconv localbase:ldflags \
		pkgconfig scons ssl tar:bzip2
USE_GNOME=	libglade2
PORTDOCS=	*
DESTDIRNAME=	FAKE_ROOT

OPTIONS_DEFINE=	NOTIFY DEBUG DOCS
OPTIONS_DEFAULT=NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MAKE_ARGS_OFF=	libnotify=0

DEBUG_MAKE_ARGS=debug=1

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	member access into incomplete type 'dh_st'
BROKEN_FreeBSD_13=	member access into incomplete type 'dh_st'
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/'iconv'/'${ICONV_LIB:S/-l//}'/" \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|g++|${CXX}|' ${WRKSRC}/SConstruct

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
