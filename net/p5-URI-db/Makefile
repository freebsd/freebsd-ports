# Created by: Henrik Hodne <henrik@hodne.io>
# $FreeBSD$

PORTNAME=	URI-db
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	henrik@hodne.io
COMMENT=	Perl5 module representing database URIs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-URI>=1.40:net/p5-URI \
		p5-URI-Nested>=0.10:net/p5-URI-Nested
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
