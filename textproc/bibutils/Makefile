# $FreeBSD$

PORTNAME=	bibutils
PORTVERSION=	6.10
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	_src.tgz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Program set interconverts between various bibliography formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/Copying

USES=		gmake

HAS_CONFIGURE=	yes
TEST_TARGET=	test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
