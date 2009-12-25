# New ports collection makefile for:	p5-Net-OpenDHT
# Date created:			21 May 2005
# Whom:				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenDHT
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access the Open Distributed Hash Table (Open DHT)

RUN_DEPENDS=	${SITE_PERL}/Class/Accessor/Chained/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		${SITE_PERL}/App/Cache.pm:${PORTSDIR}/devel/p5-App-Cache \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::OpenDHT.3

.include <bsd.port.mk>
