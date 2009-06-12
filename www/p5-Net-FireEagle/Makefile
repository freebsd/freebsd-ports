# New ports collection makefile for:	p5-Net-FireEagle
# Date created:				2008-04-02
# Whom:					Steven Kreuzer <skreuzer@exit2shel.com>
#
# $FreeBSD$
#

PORTNAME=	Net-FireEagle
PORTVERSION=	1.5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Access Yahoo's FireEagle location service

RUN_DEPENDS=	p5-Net-OAuth-Simple>=1.0:${PORTSDIR}/net/p5-Net-OAuth-Simple \
		p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-Test-Simple>=0.74:${PORTSDIR}/devel/p5-Test-Simple \
		p5-JSON-Any>=1.15:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Net-SSLeay>=1.30:${PORTSDIR}/security/p5-Net-SSLeay
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		fireeagle.1
MAN3=		Net::FireEagle.3

.include <bsd.port.mk>
