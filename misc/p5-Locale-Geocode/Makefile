# Created by: chinsan
# $FreeBSD$

PORTNAME=	Locale-Geocode
PORTVERSION=	1.20
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find codes and information on geographical location

RUN_DEPENDS=	p5-XML-SAX-Expat>=0.39:${PORTSDIR}/textproc/p5-XML-SAX-Expat \
		p5-XML-Simple>=2.16:${PORTSDIR}/textproc/p5-XML-Simple
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
