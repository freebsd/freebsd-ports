# New ports collection makefile for:	p5-Apache-Session-PHP
# Date created:				16 April 2003
# Whom:	      				Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-Session-PHP
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Glue Apache::Session with PHP::Session

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/PHP/Session.pm:${PORTSDIR}/www/p5-PHP-Session \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::Session::PHP.3 Apache::Session::Serialize::PHP.3 Apache::Session::Store::PHP.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
