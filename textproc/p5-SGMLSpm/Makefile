# Created by: Brian Candler <B.Candler@pobox.com>
# $FreeBSD$

PORTNAME=	SGMLSpm
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	SGMLS
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}ii

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for postprocessing the output from sgmls and nsgmls

USE_PERL5=	run
USES=		shebangfix perl5
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SHEBANG_FILES=	sgmlspl.pl \
		DOC/HTML/SGMLSpm/sample.pl \
		DOC/HTML/SGMLSpm/example.html

INSTALL_TARGET=	install BINDIR=${PREFIX}/bin \
		PERL5DIR=${SITE_PERL} SPECDIR=${EXAMPLESDIR}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=       *
INSTALL_TARGET+=docs install_html HTMLDIR=${DOCSDIR}
.endif

.if ! ${PORT_OPTIONS:MEXAMPLES}
EXTRA_PATCHES=	${PATCHDIR}/noportexamples-patch-Makefile
.endif

pre-su-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
