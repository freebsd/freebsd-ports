# New ports collection makefile for:	postfwd
# Date created:				8 May 2008
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	postfwd
DISTVERSION=	1.10.7b
CATEGORIES=	mail
MASTER_SITES=	http://www.postfwd.org/old/
PKGNAMEPREFIX=	postfix-
DISTNAME=	postfwd-1.10pre7b

MAINTAINER=	sahil@tandon.net
COMMENT=	A postfix firewall policy daemon

RUN_DEPENDS=	${SITE_PERL}/Net/DNS/Async.pm:${PORTSDIR}/dns/p5-Net-DNS-Async \
		${SITE_PERL}/Net/CIDR/Lite.pm:${PORTSDIR}/net/p5-Net-CIDR-Lite \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex

PORTDOCS=	CHANGELOG postfwd.html postfwd.txt
PORTEXAMPLES=	postfwd-rblcheck.pl request.sample
PLIST_FILES=	bin/postfwd etc/postfwd.conf.sample

SUB_FILES=	pkg-message

USE_RC_SUBR=	postfwd
USE_PERL5_RUN=	yes
NO_BUILD=	yes

MAN1=		postfwd.1

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.cf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${MAN1} ${MANPREFIX}/man/man1/

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/bin/postfwd-rblcheck.pl ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/request.sample ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
