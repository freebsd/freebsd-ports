# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-ASCIITable
PORTVERSION=	0.22
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create a nice formatted table using ASCII characters

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 shebangfix
USE_PERL5=	modbuild

NO_ARCH=	yes

PORTEXAMPLES=	ansi-example.pl

SHEBANG_FILES=	ansi-example.pl

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ansi-example.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
