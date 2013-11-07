# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Model-CDBI
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CDBI model class for Catalyst

BUILD_DEPENDS=	p5-Class-DBI-Loader>=0:${PORTSDIR}/databases/p5-Class-DBI-Loader \
		p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-MRO-Compat>=0.11:${PORTSDIR}/devel/p5-MRO-Compat

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
