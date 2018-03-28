# Created by: Dmitry Morozovsky <marck@FreeBSD.org>
# $FreeBSD$

PORTNAME=	List-Compare
PORTVERSION=	0.53
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	marck@FreeBSD.org
COMMENT=	Perl extension for comparing lists

LICENSE=	ART10

TEST_DEPENDS=	p5-IO-CaptureOutput>=0:devel/p5-IO-CaptureOutput

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Changes README

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
