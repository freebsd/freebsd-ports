# New ports collection makefile for:	Mail-Audit
# Date created:				Wed Jan  3 12:31:10 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Audit
PORTVERSION=	1.3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Net/Config.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
USE_PERL5=	yes
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::Audit.3

.include <bsd.port.mk>
