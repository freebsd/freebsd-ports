# Created by: dave@dogwood.com
# $FreeBSD$

PORTNAME=	olsrd
DISTVERSION=	0.6.6.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.olsr.org/releases/0.6/ \
		http://ftp2.za.freebsd.org/pub/mesh/pc/protocols/olsr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OLSR routing daemon

BUILD_DEPENDS=	makedepend:devel/makedepend

USES=		bison gmake tar:bzip2
USE_LDCONFIG=	yes
USE_RC_SUBR=	olsrd

ALL_TARGET=	build_all
INSTALL_TARGET=	install_all

OPTIONS_DEFINE=	MULTI_IF
MULTI_IF_DESC=	IPv4 multiple interface support

MULTI_IF_LIB_DEPENDS=	libnet.so:net/libnet
MULTI_IF_MAKE_ARGS=	LIBNET=1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/sbin/ldconfig|:|g' ${WRKSRC}/make/Makefile.fbsd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*

.include <bsd.port.post.mk>
