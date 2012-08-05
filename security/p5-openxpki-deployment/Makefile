# New ports collection makefile for:	p5-openxpki-deployment
# Date created:				03 Oct 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki-deployment
PORTVERSION=	0.9.1386
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	SF/openxpki/openxpki/0.9.1300
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Perl based enterprise class trustcenter software for PKI

BUILD_DEPENDS=	\
	p5-openxpki-client>=0:${PORTSDIR}/security/p5-openxpki-client \
	p5-Config-Std>=0:${PORTSDIR}/devel/p5-Config-Std \
	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN1=	openxpki-configure.1 \
	openxpki-metaconf.1 \
	openxpkiadm.1 \
	openxpkictl.1
USE_PERL5=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	openxpki
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|>/dev/null 2>&1 | |' ${WRKSRC}/configure

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "================================ A piece of advice ==================================="
	@${ECHO_MSG} "===> Install your favorite database (enable utf-8 support if needed) and a web server."
	@${ECHO_MSG} "===> Perform deployment procedure for openxpki in a regular way."
	@${ECHO_MSG} "===> When asked for the name of the \"openxpki user\" answer \"openxpki\","
	@${ECHO_MSG} "===> and do not forget to add a line: \"User openxpki\" to the zone of your"
	@${ECHO_MSG} "===> OpenXPI-related (virtual) web server in your Apache configuration file."
	@${ECHO_MSG} ""
.if !defined(BATCH)
	@sleep 9
.endif

.include <bsd.port.mk>
