# Created by: dave@dogwood.com
# $FreeBSD$

PORTNAME=	olsrd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.8
CATEGORIES=	net

MAINTAINER=	koue@chaosophia.net
COMMENT=	OLSR routing daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		bison gmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	olsrd

GH_ACCOUNT=	OLSR
MAKE_ARGS=	VERBOSE=1

ALL_TARGET=	build_all
INSTALL_TARGET=	install_all

OPTIONS_DEFINE=	MULTI_IF
MULTI_IF_DESC=	IPv4 multiple interface support

MULTI_IF_LIB_DEPENDS=	libnet.so:net/libnet
MULTI_IF_MAKE_ARGS=	LIBNET=1

post-patch:
	@${CP} ${WRKSRC}/src/cfgparser/cfgfile_gen.c \
		${WRKSRC}/src/cfgparser/olsrd_conf.h \
		${WRKSRC}/lib/httpinfo/src/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*

.include <bsd.port.mk>
