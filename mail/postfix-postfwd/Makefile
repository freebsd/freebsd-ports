# New ports collection makefile for:	postfwd
# Date created:				8 May 2008
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	postfwd
PORTVERSION=	1.35
CATEGORIES=	mail
MASTER_SITES=	http://www.${PORTNAME}.org/old/
PKGNAMEPREFIX=	postfix-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	A postfix firewall policy daemon

LICENSE=	BSD

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

PORTDOCS=	*
PORTEXAMPLES=	request.sample postfwd.plugins.sample

PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.sample
SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}
USE_PERL5_RUN=	yes
NO_BUILD=	yes

MAN8=		${PORTNAME}.8 ${PORTNAME}2.8

OPTIONS_DEFINE=	EXAMPLES DOCS POSTFWD2
POSTFWD2_DESC=	Install postfwd v2 rather than v1

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MPOSTFWD2}
	@${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME}2 ${PREFIX}/bin/${PORTNAME}
.else
	@${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME} ${PREFIX}/bin/
.endif
	@${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.cf.sample ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/man/man8/* ${MANPREFIX}/man/man8/

post-install:
.if !empty(PORT_OPTIONS:MDOCS)
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !empty(PORT_OPTIONS:MEXAMPLES)
	@${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 555 -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/request.sample ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/plugins/postfwd.plugins.sample ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
