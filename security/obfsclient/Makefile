# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	obfsclient
PORTVERSION=	0.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	9
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tor-managed pluggable transport client

LICENSE=	BSD2CLAUSE MIT ISCL BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liballium-1.0.so:devel/liballium \
		libevent.so:devel/libevent

USE_GITHUB=	yes
GH_ACCOUNT=	Yawning

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++11-lib localbase pkgconfig ssl
TEST_TARGET=	check

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	COPYING

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	field has incomplete type 'HMAC_CTX' (aka 'hmac_ctx_st')
BROKEN_FreeBSD_13=	field has incomplete type 'HMAC_CTX' (aka 'hmac_ctx_st')
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
