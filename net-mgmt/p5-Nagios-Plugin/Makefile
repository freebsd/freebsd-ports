# New ports collection makefile for:	p5-Nagios-Plugin
# Date created:				13 08 2006
# Whom:					Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	Nagios-Plugin
PORTVERSION=	0.33
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN/../../authors/id/T/TO/TONVOON
PKGNAMEPREFIX=	p5-

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Modules to streamline writing Nagios plugins

PERL_CONFIGURE=	5.8.0+

BUILD_DEPENDS+=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Math/Calc/Units.pm:${PORTSDIR}/math/p5-Math-Calc-Units \
		${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=		Nagios::Plugin.3 \
		Nagios::Plugin::Config.3 \
		Nagios::Plugin::ExitResult.3 \
		Nagios::Plugin::Functions.3 \
		Nagios::Plugin::Getopt.3 \
		Nagios::Plugin::Performance.3 \
		Nagios::Plugin::Range.3 \
		Nagios::Plugin::Threshold.3 \

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
