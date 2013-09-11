# Created by: scheidell@secnap.net
# $FreeBSD$

PORTNAME=	PDF-Table
DISTVERSION=	0.9.6_h3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	A utility class for building table layouts in a PDF::API2 object

BUILD_DEPENDS=	p5-PDF-API2>=0:${PORTSDIR}/textproc/p5-PDF-API2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.h3//}

MAN3=		PDF::Table.3

.include <bsd.port.mk>
