# Created by: mat
# $FreeBSD$

PORTNAME=	PerlPoint-Converters
PORTVERSION=	1.02.05
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert PerlPoint docs into various formats

BUILD_DEPENDS=	p5-PerlPoint-Package>=0:textproc/p5-PerlPoint-Package \
		p5-Getopt-ArgvFile>=0:devel/p5-Getopt-ArgvFile
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure patch
OPTIONS_DEFINE=	DOCS

PORTDOCS=	# suck all DOCSDIR

post-patch:
	@(cd ${WRKSRC} && ${CP} -R pp2html_styles images doc)
	@${PERL} -pi -e 's!../(images|pp2html_styles)!$$1!g' ${WRKSRC}/doc/*.cfg

post-build:
	@(cd ${WRKSRC}/doc && ${MAKE})

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
