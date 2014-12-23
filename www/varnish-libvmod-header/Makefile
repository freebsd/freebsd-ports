# Created by: anders
# $FreeBSD$

PORTNAME=	libvmod-header
DISTVERSION=	0.3-5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://anders.fupp.net/distfiles/
PKGNAMEPREFIX=	varnish-
#DISTNAME=	KristianLyng-${PORTNAME}-${VMOD_HEADER_HASH}
#DISTFILES=	KristianLyng-${PORTNAME}-${DISTVERSION}-g${VMOD_HEADER_HASH}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Varnish Module (vmod) for manipulation of duplicated headers

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/varnish/varnishapi.h:${PORTSDIR}/www/varnish \
		rst2man:${PORTSDIR}/textproc/py-docutils

USES=		autoreconf gmake libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
PLIST_FILES=	man/man3/vmod_header.3.gz lib/varnish/vmods/libvmod_header.so
WRKSRC=		${WRKDIR}/${PORTNAME}-master
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
