# New ports collection makefile for:	net/p5-NetAddr-IP-Count
# Date created:				29 March 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	NetAddr-IP-Count
PORTVERSION=	2.00
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetAddr
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@tobez.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/NetAddr/IP.pm:${PORTSDIR}/net/p5-NetAddr-IP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		NetAddr::IP::Count.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
