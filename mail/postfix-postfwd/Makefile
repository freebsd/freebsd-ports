# New ports collection makefile for:	postfwd
# Date created:				8 May 2008
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	postfwd
PORTVERSION=	1.13
CATEGORIES=	mail
MASTER_SITES=	http://www.${PORTNAME}.org/old/
PKGNAMEPREFIX=	postfix-

MAINTAINER=	sahil@tandon.net
COMMENT=	A postfix firewall policy daemon

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex

PORTDOCS=	CHANGELOG ${PORTNAME}.html ${PORTNAME}.txt
PORTEXAMPLES=	request.sample
PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.sample

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}	
USE_PERL5_RUN=	yes
NO_BUILD=	yes

MAN8=		${PORTNAME}.8

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.cf.sample ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/man/man8/${MAN8} ${MANPREFIX}/man/man8/

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 555 -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
