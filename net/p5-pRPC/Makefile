# New ports collection makefile for:	p5-pRPC
# Version required:			0.1005
# Date Created:				Aug 18 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1998/11/11 05:37:28 asami Exp $
#

DISTNAME=	pRPC-modules-0.1005
PKGNAME=	p5-pRPC-modules-0.1005
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RPC

MAINTAINER=	vanilla@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/Storable.pm:${PORTSDIR}/devel/p5-Storable

USE_PERL5=	yes

MAN3=		Bundle::pRPC-modules.3 \
		RPC::pClient.3 \
		RPC::pServer.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
