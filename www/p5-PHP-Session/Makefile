# New ports collection makefile for:	p5-PHP-Session
# Date created:				16 April 2003
# Whom:	      				Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	PHP-Session
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PHP
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Read / write PHP session files

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		PHP::Session.3 PHP::Session::Serializer::PHP.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
