# New ports collection makefile for:	MailStats
# Date created:				Wed Jan  3 15:09:46 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	MailStats
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::Stats::Record.3 Mail::Stats.3

.include <bsd.port.mk>
