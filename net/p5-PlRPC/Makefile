# New ports collection makefile for:	p5-PlRPC
# Date Created:				27 Feb 2000
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PlRPC
PORTVERSION=	0.2018
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for writing RPC servers and clients

BUILD_DEPENDS=	${SITE_PERL}/Net/Daemon.pm:${PORTSDIR}/net/p5-Net-Daemon
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Bundle::PlRPC.3 \
		RPC::PlClient.3 \
		RPC::PlServer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
