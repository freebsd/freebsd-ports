# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Template-Iterator-AlzaboWrapperCursor
DISTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turns a Class-AlzaboWrapper-Cursor object into a TT2 iterator

BUILD_DEPENDS=	p5-Template-Toolkit>=2:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Class-AlzaboWrapper>=0:${PORTSDIR}/devel/p5-Class-AlzaboWrapper
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
