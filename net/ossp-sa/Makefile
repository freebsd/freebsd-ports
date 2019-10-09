# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	sa
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction library for the Unix socket API

LIB_DEPENDS=	libex.so:devel/ossp-ex

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}
USES=		gmake libtool pathfix
USE_LDCONFIG=	yes

regression-test check: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsa.so

.include <bsd.port.mk>
