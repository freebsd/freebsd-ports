# New ports collection makefile for:	Mail-Freshmeat
# Date created:				Wed Jan  3 14:42:56 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Freshmeat
PORTVERSION=	1.20
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Freshmeat.3

.include <bsd.port.mk>
