# New ports collection makefile for:    CGI::Builder
# Date created:                         20 Oct 2004
# Whom:                                 Daniel Wijnands <daniel@itxl.nl>
#
# $FreeBSD$
#

PORTNAME=	CGI-Builder
PORTVERSION=	1.26
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}+

MAINTAINER=	daniel@itxl.nl
COMMENT=	Perl module intended to make it easier to create reusable web apps

BUILD_DEPENDS=	${SITE_PERL}/IO/Util.pm:${PORTSDIR}/devel/p5-IO-Util \
		${SITE_PERL}/Class/constr.pm:${PORTSDIR}/devel/p5-OOTools

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN3=		CGI::Builder.3  \
		CGI::Builder::Const.3 \
		CGI::Builder::Test.3 \
		Bundle::CGI::Builder::Complete.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.1 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
