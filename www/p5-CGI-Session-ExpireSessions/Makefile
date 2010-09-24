# New ports collection makefile for:	p5-CGI-Session-ExpireSessions
# Date created:		11 March 2009
# Whom:			Gerard Seibert <gerard@seibercom.net>
#
# $FreeBSD$
#

PORTNAME=	CGI-Session-ExpireSessions
PORTVERSION=	1.09
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gerard@seibercom.net
COMMENT=	Perl module to delete expired CGI::Session-type sessions

BUILD_DEPENDS=	p5-Test-Pod>=1.26:${PORTSDIR}/devel/p5-Test-Pod
RUN_DEPENDS=	p5-CGI-Session>=4.40:${PORTSDIR}/www/p5-CGI-Session

MAN3=	CGI::Session::ExpireSessions.3
MANCOMPRESSED=	no

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
