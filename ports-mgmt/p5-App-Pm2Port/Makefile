# Created by: andrey@kostenko.name
# $FreeBSD$

PORTNAME=	App-Pm2Port
PORTVERSION=	0.29
PORTREVISION=	3
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Creating port from perl module

DEPRECATED=	Does not know about USES=perl, generates incorrect pkg-plist
EXPIRATION_DATE=	2015-01-06

BUILD_DEPENDS=	p5-CPANPLUS>=0:${PORTSDIR}/devel/p5-CPANPLUS \
		p5-FreeBSD-Ports-INDEXhash>=0:${PORTSDIR}/ports-mgmt/p5-FreeBSD-Ports-INDEXhash \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		subversion>=0:${PORTSDIR}/devel/subversion
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
