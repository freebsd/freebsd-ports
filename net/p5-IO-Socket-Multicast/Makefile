# New ports collection makefile for:	p5-IO-Socket-Multicast
# Date created:		10 Sep 2002
# Whom:	      		Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-Multicast
PORTVERSION=	0.25
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR= IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kbyanc@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Interface.pm:${PORTSDIR}/net/p5-IO-Interface
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		IO::Socket::Multicast.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
