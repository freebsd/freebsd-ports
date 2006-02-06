# New ports collection makefile for:	net/p5-POE-Component-ControlPort
# Date created:				05 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-ControlPort
PORTVERSION=	0.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Network control port for POE applications

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/Authen/Libwrap.pm:${PORTSDIR}/security/p5-Authen-Libwrap \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::ControlPort.3 \
	POE::Component::ControlPort::Command.3 \
	POE::Component::ControlPort::DefaultCommands.3

.include <bsd.port.pre.mk>

post-extract:
	@${PERL} -0pi -e 's/my \$$prompt.+(my \$$ret = )(?-s).+/$${1}0;/so' ${WRKSRC}/Makefile.PL

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\W\w+);/use vars q($$1);/o;' \
		-e 's/^our\s+(\W\w+)(?!;)/use vars q($$1); $$1/o;' \
		-e 'undef $$_ if /^\s*(no|use) warnings/o;' \
		${WRKSRC}/lib/POE/Component/ControlPort.pm \
		${WRKSRC}/lib/POE/Component/ControlPort/DefaultCommands.pm \
		${WRKSRC}/lib/POE/Component/ControlPort/Command.pm
.endif

.include <bsd.port.post.mk>
