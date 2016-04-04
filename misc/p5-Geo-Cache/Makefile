# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Cache
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	misc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Object interface for GPS waypoints

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Time-modules>=0:devel/p5-Time-modules \
		p5-XML-Simple>=0:textproc/p5-XML-Simple
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
