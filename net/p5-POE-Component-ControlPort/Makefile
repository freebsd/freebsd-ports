# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	POE-Component-ControlPort
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Network control port for POE applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Authen-Libwrap>=0:security/p5-Authen-Libwrap \
		p5-POE>=0:devel/p5-POE
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|\(my $$ret = \).*|\1 0;|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
