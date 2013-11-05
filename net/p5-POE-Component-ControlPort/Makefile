# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	POE-Component-ControlPort
PORTVERSION=	0.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Network control port for POE applications

RUN_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Authen-Libwrap>=0:${PORTSDIR}/security/p5-Authen-Libwrap \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure extract

post-extract:
	@${PERL} -pi -e 's/my \$$ret =.*/my \$$ret = 0;/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
