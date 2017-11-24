# Created by: Stefan Hagen <ports@textmail.me>
# $FreeBSD$

PORTNAME=	pdfstitch
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6
CATEGORIES=	print

MAINTAINER=	ports@textmail.me
COMMENT=	Crop and stitch pages from PDF to larger, single-page PDF

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	p5-YAML>=1.10:textproc/p5-YAML \
		p5-File-LibMagic>=1.10:devel/p5-File-LibMagic \
		p5-PDF-API2>=2.030:textproc/p5-PDF-API2

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	sur5r

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdfstitch ${STAGEDIR}${PREFIX}/bin/pdfstitch
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
