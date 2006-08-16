# New ports collection makefile for:	p5-MediaWiki
# Date created:		2006-08-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	MediaWiki
PORTVERSION=	1.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/SP/SPECTRUM/
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	OOP MediaWiki engine client

RUN_DEPENDS=	${SITE_PERL}/Config/IniHash.pm:${PORTSDIR}/devel/p5-Config-IniHash \
		${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		MediaWiki.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 #inherited from www/p5-libwww
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
