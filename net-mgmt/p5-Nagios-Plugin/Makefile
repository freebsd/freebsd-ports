# New ports collection makefile for:	p5-Nagios-Plugin
# Date created:				13 08 2006
# Whom:					Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	Nagios-Plugin
PORTVERSION=	0.34
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TONVOON
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modules to streamline writing Nagios plugins

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Math-Calc-Units>=0:${PORTSDIR}/math/p5-Math-Calc-Units \
		p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

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
