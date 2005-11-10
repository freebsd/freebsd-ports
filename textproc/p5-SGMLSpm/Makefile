# New ports collection makefile for:	SGMLSpm
# Date created:		4 May 2004
# Whom:			Brian Candler <B.Candler@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	SGMLSpm
PORTVERSION=	1.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SGMLS
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}ii

MAINTAINER=	B.Candler@pobox.com
COMMENT=	Perl module for postprocessing the output from sgmls and nsgmls

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

pre-install:
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}

INSTALL_TARGET=	install PERL5DIR=${SITE_PERL} SPECDIR=${EXAMPLESDIR}
.ifndef(NOPORTDOCS)
PORTDOCS=	*
INSTALL_TARGET+=docs install_html HTMLDIR=${DOCSDIR}
.endif

.include <bsd.port.mk>
