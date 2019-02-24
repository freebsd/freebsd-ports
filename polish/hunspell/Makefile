# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20190224
CATEGORIES=	polish textproc
MASTER_SITES=	https://sjp.pl/slownik/ort/ \
		LOCAL/sunpoet/${PORTNAME}
DISTNAME=	sjp-myspell-pl-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Polish hunspell dictionaries

LICENSE=	APACHE20 CC-BY-NC-SA-1.0 GPLv3 LGPL3 MPL11
LICENSE_COMB=	dual

USES=		zip

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/pl_PL.aff \
		%%DATADIR%%/pl_PL.dic

post-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -xf ${WRKDIR}/pl_PL.zip --directory ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pl_PL.aff ${WRKSRC}/pl_PL.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
