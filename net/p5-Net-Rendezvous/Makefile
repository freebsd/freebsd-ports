# New ports collection makefile for:    Net-Rendezvous
# Date created:                         Fri Feb 20 17:39:48 EST 2004
# Whom:                                 Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	Net-Rendezvous
PORTVERSION=	0.90
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A set of perl modules to utilize mDNS for service discovery

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Rendezvous.3 \
	Net::Rendezvous::Entry.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
IGNORE=	"perl 5.6 or higher is required to build this port"
.endif

.include <bsd.port.post.mk>
