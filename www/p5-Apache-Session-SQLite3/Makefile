# Created by: clsung
# $FreeBSD$

PORTNAME=	Apache-Session-SQLite3
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Use DBD::SQLite 1.x for Apache::Session storage

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Apache-Session>=0:www/p5-Apache-Session \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
