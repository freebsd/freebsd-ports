# New ports collection makefile for:	p5-CGI-Untaint
# Date created:	   21 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	CGI-Untaint
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Process CGI input parameters

RUN_DEPENDS=	${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		CGI::Untaint.3 CGI::Untaint::hex.3 CGI::Untaint::integer.3 \
       		CGI::Untaint::object.3 CGI::Untaint::printable.3

.include <bsd.port.mk>
