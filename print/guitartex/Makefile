# ex:ts=8
# New ports collection makefile for:	GuitarTeX
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	guitartex
PORTVERSION=	2.8.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
## Hack just for this "fix version"
DISTNAME=	${PORTNAME}-${PORTVERSION}-fix1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GuitarTeX converts the Chord format into "normal" LaTeX format

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk \
		latex:${PORTSDIR}/print/latex

USE_REINPLACE=	yes
USE_PERL5=	yes
NO_BUILD=	yes

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
