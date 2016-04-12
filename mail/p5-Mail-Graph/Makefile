# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Mail-Graph
PORTVERSION=	0.14
PORTREVISION=	8
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for drawing graphical stats for mails/spams

RUN_DEPENDS=	p5-GD>=0:graphics/p5-GD \
		p5-GD-Graph>=0:graphics/p5-GD-Graph \
		p5-GD-TextUtil>=0:graphics/p5-GD-TextUtil \
		p5-Date-Calc>=0:devel/p5-Date-Calc
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure
EXAMPLESCRIPT=	samples/*pl
EXAMPLEDUMMY=	samples/index/dummy.txt
EXAMPLEOUTPUT=	samples/output/w3c.png samples/output/spam.css
EXAMPLEARCHIVE=	samples/archive/*.gz

SHEBANG_FILES=	samples/*.pl

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/archive \
		${STAGEDIR}${EXAMPLESDIR}/index ${STAGEDIR}${EXAMPLESDIR}/output
	(cd ${WRKSRC} && \
	${INSTALL_SCRIPT} ${EXAMPLESCRIPT} ${STAGEDIR}${EXAMPLESDIR}  && \
	${INSTALL_SCRIPT} ${EXAMPLEDUMMY} ${STAGEDIR}${EXAMPLESDIR}/index && \
	${INSTALL_SCRIPT} ${EXAMPLEOUTPUT} ${STAGEDIR}${EXAMPLESDIR}/output && \
	${INSTALL_SCRIPT} ${EXAMPLEARCHIVE} ${STAGEDIR}${EXAMPLESDIR}/archive)

.include <bsd.port.mk>
