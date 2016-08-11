# Created by: dave@dogwood.com
# $FreeBSD$

PORTNAME=	olsrd
DISTVERSION=	0.9.0.3
CATEGORIES=	net
MASTER_SITES=	http://www.olsr.org/releases/0.9/

MAINTAINER=	koue@chaosophia.net
COMMENT=	OLSR routing daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		bison gmake tar:bzip2
USE_LDCONFIG=	yes
USE_RC_SUBR=	olsrd

ALL_TARGET=	build_all
INSTALL_TARGET=	install_all

OPTIONS_DEFINE=	MULTI_IF
MULTI_IF_DESC=	IPv4 multiple interface support

MULTI_IF_LIB_DEPENDS=	libnet.so:net/libnet
MULTI_IF_MAKE_ARGS=	LIBNET=1

CFLAGS_ia64=	-fPIC
CFLAGS_amd64=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e 's|/sbin/ldconfig|:|g' ${WRKSRC}/make/Makefile.fbsd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*

.include <bsd.port.mk>
