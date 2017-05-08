# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	SVG
PORTVERSION=	2.75
CATEGORIES=	textproc graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for generating Scalable Vector Graphics (SVG) documents

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	EXAMPLES

USES=		dos2unix perl5 shebangfix
SHEBANG_FILES=	examples/*.pl examples/*.cgi examples/*.psgi
USE_PERL5=	configure
NO_ARCH=	yes

PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
