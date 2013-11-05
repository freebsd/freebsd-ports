# Created by: snowchyld
# $FreeBSD$

PORTNAME=	Hash-Merge
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}0

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Merges hashes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
