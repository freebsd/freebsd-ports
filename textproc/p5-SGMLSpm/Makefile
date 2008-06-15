# New ports collection makefile for:	SGMLSpm
# Date created:		4 May 2004
# Whom:			Brian Candler <B.Candler@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	SGMLSpm
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	SGMLS
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}ii

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for postprocessing the output from sgmls and nsgmls

USE_PERL5_RUN=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

INSTALL_TARGET=	install BINDIR=${PREFIX}/bin \
		PERL5DIR=${SITE_PERL} SPECDIR=${EXAMPLESDIR}

.ifndef(NOPORTDOCS)
PORTDOCS=       *
INSTALL_TARGET+=docs install_html HTMLDIR=${DOCSDIR}
.endif
.ifdef(NOPORTEXAMPLES)
EXTRA_PATCHES=	${PATCHDIR}/noportexamples-patch-Makefile
.endif

pre-su-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.endif
.ifndef(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.endif

.ifndef(NOPORTDOCS)
PORTDOCS=	*
INSTALL_TARGET+=docs install_html HTMLDIR=${DOCSDIR}
.endif

.include <bsd.port.mk>
