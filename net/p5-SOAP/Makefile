# Created by: will
# $FreeBSD$

PORTNAME=	SOAP
PORTVERSION=	0.28
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Perl modules providing an API to the Simple Object Access Protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-SOAP-Lite-[0-9]*

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
