# Created by: tj@FreeBSD.org
# $FreeBSD$

PORTNAME=	Text-CSV-Hashify
PORTVERSION=	0.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEENAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Composition and decomposition of comma-separated values into hashes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Text-CSV>=0:textproc/p5-Text-CSV
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
