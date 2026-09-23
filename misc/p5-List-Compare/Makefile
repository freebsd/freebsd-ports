PORTNAME=	List-Compare
DISTVERSION=	0.53
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEENAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	marck@FreeBSD.org
COMMENT=	Perl extension for comparing lists
WWW=		https://metacpan.org/release/List-Compare

LICENSE=	ART10

TEST_DEPENDS=	p5-IO-CaptureOutput>=0:devel/p5-IO-CaptureOutput

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTDOCS=	Changes README

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
