# $FreeBSD$

PORTNAME=	PerlPoint-Package
PORTVERSION=	0.45.2
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Presentation and documentation toolset

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Digest-SHA1>=0:security/p5-Digest-SHA1

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	# suck all DOCSDIR

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} utilities ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
