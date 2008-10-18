# New ports collection makefile for:	postfwd
# Date created:				8 May 2008
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	postfwd
DISTVERSION=	1.10.8b
CATEGORIES=	mail
MASTER_SITES=	http://www.postfwd.org/old/
PKGNAMEPREFIX=	postfix-
DISTNAME=	postfwd-1.10pre8b

MAINTAINER=	sahil@tandon.net
COMMENT=	A postfix firewall policy daemon

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex

PORTDOCS=	CHANGELOG postfwd.html postfwd.txt
PORTEXAMPLES=	request.sample
PLIST_FILES=	bin/postfwd etc/postfwd.conf.sample

SUB_FILES=	pkg-message

USE_RC_SUBR=	postfwd
USE_PERL5_RUN=	yes
NO_BUILD=	yes

MAN8=		postfwd.8

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.cf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/man/man8/${MAN8} ${MANPREFIX}/man/man8/

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/request.sample ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
