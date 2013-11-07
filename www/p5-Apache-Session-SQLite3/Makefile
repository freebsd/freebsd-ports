# Created by: clsung
# $FreeBSD$

PORTNAME=	Apache-Session-SQLite3
PORTVERSION=	0.03
CATEGORIES=	www databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use DBD::SQLite 1.x for Apache::Session storage

BUILD_DEPENDS=	p5-Apache-Session>=0:${PORTSDIR}/www/p5-Apache-Session \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
