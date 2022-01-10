PORTNAME=	bibutils
PORTVERSION=	7.2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	_src.tgz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Program set interconverts between various bibliography formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/Copying

USES=		cpe gmake

CONFLICTS_INSTALL=	bib2html # bin/bib2xml

HAS_CONFIGURE=	yes
TEST_TARGET=	test

CPE_VENDOR=	bibutils_project

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
