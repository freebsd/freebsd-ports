# New ports collection makefile for:	p5-IO-Socket-Multicast
# Date created:		21 March 2002
# Whom:	      		Janos.Mohacsi@dante.org.uk
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-Multicast
PORTVERSION=	0.25
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Perl module to send and receive multicast messages

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/Interface.pm:${PORTSDIR}/net/p5-IO-Interface
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		IO::Socket::Multicast.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
