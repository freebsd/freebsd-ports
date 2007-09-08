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

.include <bsd.port.mk>
