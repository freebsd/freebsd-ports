# Created by: Christopher Boumenot <boumenot@gmail.com>
# $FreeBSD$

PORTNAME=	Net-TiVo
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	eg@fbsd.lt
COMMENT=	Framework for accessing TiVo using XML/HTTP

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
