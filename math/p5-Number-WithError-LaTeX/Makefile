# New ports collection makefile for:	Number-WithError-LaTeX
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Number-WithError-LaTeX
PORTVERSION=	0.02
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Number
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	LaTeX output for Number::WithError

BUILD_DEPENDS=	${SITE_PERL}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		${SITE_PERL}/prefork.pm:${PORTSDIR}/devel/p5-prefork \
		${SITE_PERL}/Math/SymbolicX/Inline.pm:${PORTSDIR}/math/p5-Math-SymbolicX-Inline \
		${SITE_PERL}/Number/WithError.pm:${PORTSDIR}/math/p5-Number-WithError \
		${SITE_PERL}/TeX/Encode.pm:${PORTSDIR}/textproc/p5-TeX-Encode
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Number::WithError::LaTeX.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
