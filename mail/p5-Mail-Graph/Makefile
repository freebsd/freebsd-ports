# New ports collection makefile for:	p5-Mail-Graph
# Date created:				Nov 4 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Mail-Graph
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for drawing graphical stats for mails/spams

BUILD_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil \
		${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
EXAMPLESCRIPT=	samples/*pl
EXAMPLEDUMMY=	samples/index/dummy.txt
EXAMPLEOUTPUT=	samples/output/w3c.png samples/output/spam.css
EXAMPLEARCHIVE=	samples/archive/*.gz

MAN3=	Mail::Graph.3

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/archive
	@${MKDIR} ${EXAMPLESDIR}/index
	@${MKDIR} ${EXAMPLESDIR}/output
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} ${EXAMPLESCRIPT} ${EXAMPLESDIR}  && \
	${INSTALL_SCRIPT} ${EXAMPLEDUMMY} ${EXAMPLESDIR}/index && \
	${INSTALL_SCRIPT} ${EXAMPLEOUTPUT} ${EXAMPLESDIR}/output && \
	${INSTALL_SCRIPT} ${EXAMPLEARCHIVE} ${EXAMPLESDIR}/archive

.include <bsd.port.mk>
