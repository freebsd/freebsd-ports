# Ports collection makefile for:	Net::OAuth::Simple
# Date created:			Apr 1, 2009
# Whom:				skreuzer
#
# $FreeBSD$
#

PORTNAME=	Net-OAuth-Simple
PORTVERSION=	1.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simple wrapper around the OAuth protocol

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0.57:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-libwww>=5.825:${PORTSDIR}/www/p5-libwww \
		p5-Net-OAuth>=0.14:${PORTSDIR}/net/p5-Net-OAuth \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI \
		p5-Test-Simple>=0.86:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Net::OAuth::Simple.3

.include <bsd.port.mk>
