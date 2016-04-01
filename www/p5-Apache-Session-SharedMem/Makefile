# Created by: vanilla
# $FreeBSD$

PORTNAME=	Apache-Session-SharedMem
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Apache::Session extension that store session in shared memory

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IPC-Cache>=0:devel/p5-IPC-Cache \
		p5-Apache-Session>=0:www/p5-Apache-Session
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
