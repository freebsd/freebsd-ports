# New ports collection makefile for:	WWW-Babelfish
# Date created:				Wed Jan  3 08:00:30 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	WWW-Babelfish
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Babelfish.3

.include <bsd.port.mk>
