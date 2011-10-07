# New ports collection makefile for:	p5-Net-HTTP
# Date created:				2011-04-15
# Whom:					Frederic Culot <culot@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-HTTP
PORTVERSION=	6.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Low-level HTTP client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Compress-Raw-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib \
		p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
		p5-IO-Socket-SSL>=1.38:${PORTSDIR}/security/p5-IO-Socket-SSL
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	p5-libwww-5*

MAN3=		Net::HTTP.3 \
		Net::HTTP::NB.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
