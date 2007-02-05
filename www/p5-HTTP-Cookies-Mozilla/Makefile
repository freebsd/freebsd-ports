# New ports collection makefile for:	p5-HTTP-Cookies-Mozilla
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Cookies-Mozilla
PORTVERSION=	1.10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cookie storage and management for Mozilla

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Cookies.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Cookies::Mozilla.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# inherited from www/p5-libwww
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
