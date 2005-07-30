# New ports collection makefile for:	p5-IO-INET6
# Date created:		02 July 2003
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-INET6
PORTVERSION=	2.51
PORTREVISION=	1
CATEGORIES=	net perl5 ipv6
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Perl module with object interface to AF_INET6 domain sockets

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		IO::Socket::INET6.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/5.005_03.diff
.endif

.include <bsd.port.post.mk>

