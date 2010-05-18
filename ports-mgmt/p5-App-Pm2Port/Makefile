# New ports collection makefile for:  App-Pm2Port
# Date created: 20 December 2009
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	App-Pm2Port
PORTVERSION=	0.29
PORTREVISION=	2
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Creating port from perl module

BUILD_DEPENDS=	p5-CPANPLUS>=0:${PORTSDIR}/devel/p5-CPANPLUS \
		p5-FreeBSD-Ports-INDEXhash>=0:${PORTSDIR}/ports-mgmt/p5-FreeBSD-Ports-INDEXhash \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		subversion>=0:${PORTSDIR}/devel/subversion
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.10.0+
MAN1=		pm2port.1
MAN3=		App::Pm2Port.3

.include <bsd.port.mk>
