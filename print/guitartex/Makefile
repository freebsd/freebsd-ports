# Created by: ijliao
# $FreeBSD$

PORTNAME=	guitartex
PORTVERSION=	2.8.2
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/GuitarTeX/GuitarTeX-${PORTVERSION}
## Hack just for this "fix version"
DISTNAME=	${PORTNAME}-${PORTVERSION}-fix1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GuitarTeX converts the Chord format into "normal" LaTeX format

RUN_DEPENDS=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		latex:${PORTSDIR}/print/latex

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USES=		perl5
NO_BUILD=	yes

NO_STAGE=	yes
do-configure:
	@${REINPLACE_CMD} -e 's!/usr/local/lib/guitartex!${DATADIR}!g' ${WRKSRC}/gtx2tex.pl
	@${REINPLACE_CMD} -e 's!/usr/local/lib/guitartex!${DATADIR}!g' ${WRKSRC}/guitartex.pl

do-install:
	${INSTALL} ${WRKSRC}/gtx2tex.pl ${PREFIX}/bin
	${INSTALL} ${WRKSRC}/guitartex.pl ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/guitartex.conf ${DATADIR}
	@${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/* ${DATADIR}/images
	@${MKDIR} ${DATADIR}/language
	${INSTALL_DATA}  ${WRKSRC}/language/* ${DATADIR}/language/
	@${MKDIR} ${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/* ${DATADIR}/templates

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rp ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
