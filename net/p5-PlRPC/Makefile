# New ports collection makefile for:	p5-PlRPC
# Date Created:				27 Feb 2000
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PlRPC
PORTVERSION=	0.2015
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/Daemon.pm:${PORTSDIR}/net/p5-Net-Daemon \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable

PERL_CONFIGURE=	yes

MAN3=		Bundle::PlRPC.3 \
		RPC::PlClient.3 \
		RPC::PlServer.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
