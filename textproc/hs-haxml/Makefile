# New ports collection makefile for:	HaXml
# Date created:				01 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haxml
PORTVERSION=	1.05
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/HaXml/
DISTNAME=	HaXml-${PORTVERSION}

MAINTAINER=	obraun@informatik.unibw-muenchen.de

BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98

USE_GMAKE=	yes

do-install:
	@(cd ${WRKSRC} && ${INSTALL_PROGRAM} Canonicalise DrIFT DtdToHaskell Xtract ${PREFIX}/bin)
	@${MKDIR} ${PREFIX}/lib/haxml
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib/haxml
.if !defined(NOPORTDOCS)
	@${RM} -rf ${WRKSRC}/docs/CVS
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${CP} -R docs/* ${DOCSDIR})
.endif

.include <bsd.port.mk>
