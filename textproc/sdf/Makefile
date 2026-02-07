PORTNAME=	sdf
PORTVERSION=	2.001
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IANC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple Document Format - "author-friendly" mark-up system

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
