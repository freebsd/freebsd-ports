# New ports collection makefile for:	net/p5-POE-Component-ControlPort
# Date created:				05 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-ControlPort
PORTVERSION=	0.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Network control port for POE applications

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/Authen/Libwrap.pm:${PORTSDIR}/security/p5-Authen-Libwrap \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	POE::Component::ControlPort.3 \
	POE::Component::ControlPort::Command.3 \
	POE::Component::ControlPort::DefaultCommands.3

post-extract:
	@${PERL} -pi -e 's/my \$$ret =.*/my \$$ret = 0;/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
