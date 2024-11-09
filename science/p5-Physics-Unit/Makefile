PORTNAME=	Physics-Unit
PORTVERSION=	0.60
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate Physics units and dimensions
WWW=		https://metacpan.org/release/Physics-Unit

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/eg/ && ${COPYTREE_SHARE} '*.pl' ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
