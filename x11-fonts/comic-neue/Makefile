# $FreeBSD$

PORTNAME=	comic-neue
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/crozynski/comicneue/archive/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Comic Sans alternative

LICENSE=	OFL11
LICENSE_FILE=	${WRKDIR}/comicneue-${PORTVERSION}/SIL-License.txt

USES=		fonts zip

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/comicneue-${PORTVERSION}/OTF

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
