# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Syntax-Highlight-Engine-Kate
PORTVERSION=	0.13
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Port of the syntax highlight engine of the Kate texteditor

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Differences>=0.610:devel/p5-Test-Differences \
		p5-Test-Warn>=0.30:devel/p5-Test-Warn

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/hlansi.pl bin/hlhtml.pl
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
