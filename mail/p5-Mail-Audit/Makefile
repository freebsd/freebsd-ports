# New ports collection makefile for:	Mail-Audit
# Date created:				Wed Jan  3 12:31:10 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Audit
PORTVERSION=	1.8
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Net/Config.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::Audit.3 Mail::Audit::KillDups.3 Mail::Audit::MAPS.3 \
		Mail::Audit::PGP.3

.include <bsd.port.mk>
