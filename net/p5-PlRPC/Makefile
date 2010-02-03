# New ports collection makefile for:	p5-PlRPC
# Date Created:				27 Feb 2000
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PlRPC
PORTVERSION=	0.2020
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	RPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for writing RPC servers and clients

BUILD_DEPENDS=	${SITE_PERL}/Net/Daemon.pm:${PORTSDIR}/net/p5-Net-Daemon
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		Bundle::PlRPC.3 \
		RPC::PlClient.3 \
		RPC::PlServer.3

post-patch:
	@${FIND} ${WRKSRC} -name ".svn" | ${XARGS} ${RM} -rf
	@${PERL} -pi -e 's/perldoc -t/echo perldoc -t/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
