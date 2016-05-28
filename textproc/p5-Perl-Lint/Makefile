# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Perl-Lint
PORTVERSION=	0.24
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MOZNION
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Yet another Perl source code linter

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Keywords>=0:devel/p5-B-Keywords \
		p5-Compiler-Lexer>=0.22:devel/p5-Compiler-Lexer \
		p5-Email-Address>=0:mail/p5-Email-Address \
		p5-List-Flatten>=0:devel/p5-List-Flatten \
		p5-List-MoreUtils>=0.33:lang/p5-List-MoreUtils \
		p5-Path-Tiny>=0.068:devel/p5-Path-Tiny \
		p5-Regexp-Lexer>=0.05:devel/p5-Regexp-Lexer \
		p5-String-CamelCase>=0:textproc/p5-String-CamelCase \
		p5-Test-Deep>=0:devel/p5-Test-Deep
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Text-TestBase>=0:textproc/p5-Text-TestBase

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	lint.pl lint_string.pl

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/eg/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502000
BUILD_DEPENDS+=	p5-Module-Pluggable>=0:devel/p5-Module-Pluggable
RUN_DEPENDS+=	p5-Module-Pluggable>=0:devel/p5-Module-Pluggable
.else
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.41:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.41:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
