# Created by: arved
# $FreeBSD$

PORTNAME=	XML-RAI
PORTVERSION=	1.3031
PORTEPOCH=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RSS Abstraction Interface

LICENSE=	ART10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-RSS-Parser>=0:textproc/p5-XML-RSS-Parser \
		p5-TimeDate>=0:devel/p5-TimeDate

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
