# New ports collection makefile for:	p5-IO-Socket-SSL
# Date created:				October 27th 2000
# Whom:	      				Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-SSL
PORTVERSION=	0.95
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	scrappy@FreeBSD.org
COMMENT=	Perl5 interface to SSL sockets

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IO::Socket::SSL.3

.include <bsd.port.mk>
