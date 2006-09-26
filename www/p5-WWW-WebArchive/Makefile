# New ports collection makefile for:	p5-WWW-WebArchive
# Date created:		2006-08-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-WebArchive
PORTVERSION=	0.50
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Retrieve old versions of public web pages from various web archives

RUN_DEPENDS=	${SITE_PERL}/App/Options.pm:${PORTSDIR}/devel/p5-App-Options \
		${SITE_PERL}/App/Trace.pm:${PORTSDIR}/devel/p5-App-Trace \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize

PERL_CONFIGURE=	yes

MAN3=		WWW::WebArchive.3 WWW::WebArchive::Agent.3 \
		WWW::WebArchive::WaybackMachine.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601	# Inherited from www/p5-WWW-Mechanize
IGNORE=		requires Perl 5.6.1 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
