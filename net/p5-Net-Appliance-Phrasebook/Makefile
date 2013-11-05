# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Appliance-Phrasebook
PORTVERSION=	2.103.642
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Network appliance command-line phrasebook

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Data-Phrasebook>=0:${PORTSDIR}/textproc/p5-Data-Phrasebook \
		p5-Data-Phrasebook-Loader-YAML>=0:${PORTSDIR}/textproc/p5-Data-Phrasebook-Loader-YAML \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
