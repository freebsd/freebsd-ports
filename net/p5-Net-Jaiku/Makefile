# ex:ts=8
# Ports collection makefile for:	Net::Jaiku
# Date created:		Jun 3, 2008
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Jaiku
PORTVERSION=	0.0501
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A perl interface to jaiku.com's API

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-JSON-Any>0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-JSON-Any>0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate

USES=		perl5
USE_PERL5=	configure

MAN3=	Net::Jaiku.3

.include <bsd.port.mk>
