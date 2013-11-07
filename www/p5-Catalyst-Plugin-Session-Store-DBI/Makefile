# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session-Store-DBI
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Store your sessions in a database

BUILD_DEPENDS=	p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=5.49:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
