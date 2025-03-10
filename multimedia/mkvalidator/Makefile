PORTNAME=	mkvalidator
PORTVERSION=	0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/matroska/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line tool to verify Matroska and WebM files
WWW=		https://www.matroska.org/downloads/mkvalidator.html

LICENSE=	BSD3CLAUSE BSD4CLAUSE GPLv2
LICENSE_COMB=	multi

USES=		cmake cpe tar:bzip2
CPE_VENDOR=	matroska

post-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/mkvalidator/mkvalidator ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libmatroska2/mkvtree ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
