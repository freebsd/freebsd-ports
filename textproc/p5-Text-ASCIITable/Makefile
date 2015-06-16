# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-ASCIITable
PORTVERSION=	0.20
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Create a nice formatted table using ASCII characters

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5 shebangfix
SHEBANG_FILES=	ansi-example.pl
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	ansi-example.pl

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ansi-example.pl ${STAGEDIR}${EXAMPLESDIR}

regression-test: build
	cd ${WRKSRC}/ && ./Build test

.include <bsd.port.mk>
