PORTNAME=	bpmf-zihiserif
PORTVERSION=	1.500
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/ButTaiwan/bpmfvs/releases/download/v${PORTVERSION}/
DISTNAME=	BpmfZihiSerif
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Bopomofo IVS version of Zihi Serif font family
WWW=		https://github.com/ButTaiwan/bpmfvs

LICENSE=	APACHE20 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-2.0.txt
LICENSE_FILE_OFL11=	${WRKSRC}/LICENSE-ZihiSerif.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/NOTICE.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
