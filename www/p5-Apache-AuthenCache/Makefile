# New ports collection makefile for:	Apache-AuthenCache
# Date created:				Sun Dec 31 19:59:31 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthenCache
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::AuthenCache.3

.include <bsd.port.mk>
