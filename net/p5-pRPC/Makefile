# New ports collection makefile for:	p5-pRPC
# Date Created:				Aug 18 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-pRPC-modules
PORTVERSION=	0.1005
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RPC
DISTNAME=	pRPC-modules-0.1005

MAINTAINER=	vanilla@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/Storable.pm:${PORTSDIR}/devel/p5-Storable

USE_PERL5=	yes

MAN3=		Bundle::pRPC-modules.3 \
		RPC::pClient.3 \
		RPC::pServer.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
