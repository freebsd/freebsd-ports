# New ports collection makefile for:	www/p5-CGI-Application-Plugin-ViewCode
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-ViewCode
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	View the source of the running application

RUN_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CGI/Application/Plugin/Forward.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-Forward \
		${SITE_PERL}/Syntax/Highlight/Perl/Improved.pm:${PORTSDIR}/textproc/p5-Syntax-Highlight-Perl-Improved \
		${SITE_PERL}/Pod/Xhtml.pm:${PORTSDIR}/textproc/p5-Pod-Xhtml \
		${SITE_PERL}/Test/LongString.pm:${PORTSDIR}/devel/p5-Test-LongString
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Plugin::ViewCode.3

.include <bsd.port.mk>
