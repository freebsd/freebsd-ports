# Created by: Brian Candler <B.Candler@pobox.com>
# $FreeBSD$

PORTNAME=	SGMLSpm
PORTVERSION=	1.03
DISTVERSIONSUFFIX=	ii
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/SGMLS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for postprocessing the output from sgmls and nsgmls

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PERL5=	run
USES=		shebangfix perl5
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SHEBANG_FILES=	sgmlspl.pl \
		DOC/sample.pl \
		DOC/HTML/SGMLSpm/example.html

INSTALL_TARGET=	install BINDIR=${STAGEDIR}${PREFIX}/bin \
		PERL5DIR=${STAGEDIR}${PREFIX}/${SITE_PERL_REL} SPECDIR=${STAGEDIR}${EXAMPLESDIR}

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*

DOCS_INSTALL_TARGET=	docs install_html HTMLDIR=${STAGEDIR}${DOCSDIR}

pre-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
