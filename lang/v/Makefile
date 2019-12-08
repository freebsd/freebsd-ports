# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	v
PORTVERSION=	0.1.22
CATEGORIES=	lang

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	V Programming Language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

LDFLAGS+=	-lm

PLIST_FILES=	bin/v

GH_ACCOUNT=	vlang
GH_TUPLE=	vlang:vc:0.1.20:vc/vc
USE_GITHUB=	yes

do-build:
	${CC} ${CLFAGS} ${LDFLAGS} ${WRKSRC}/vc/v.c -o ${WRKSRC}/v

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/v ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
