# New ports collection makefile for:	Xitami HTTP Server
# Date created:		15 Oct 1997
# Whom:			Ian Vaudrey <i.vaudrey@cableinet.co.uk>
#
# $FreeBSD$
#

PORTNAME=	xitami
PORTVERSION= 	2.4d7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://users.skynet.be/sky37432/
DISTNAME=	suni24d7
EXTRACT_SUFX=	.tgz

MAINTAINER=	bdluevel@heitec.net
COMMENT=	A fast, portable multithreaded web server

NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

do-build:
	@${CHMOD} +x ${WRKSRC}/xibuild
	@${SETENV} TOPDIR=${WRKSRC} ${SH} ${WRKSRC}/xibuild

do-install:
	@${MKDIR} ${PREFIX}/xitami/cgi-bin
	@${MKDIR} ${PREFIX}/xitami/webpages
	@${CAT} ${FILESDIR}/defaults.cfg.tmpl | ${SED} s:PREFIX:${PREFIX}: > ${WRKDIR}/defaults.cfg
	@${INSTALL_DATA} ${WRKDIR}/defaults.cfg ${PREFIX}/xitami/defaults.cfg.sample
	@${INSTALL_DATA} ${FILESDIR}/xitami.aut ${PREFIX}/xitami
	@${CHMOD} u+w ${PREFIX}/xitami/*
	@${INSTALL_DATA} ${WRKSRC}/src/smt/xitami.cfg ${PREFIX}/xitami
	@${INSTALL_PROGRAM} ${WRKSRC}/src/smt/xitami ${PREFIX}/xitami
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/testcgi ${PREFIX}/xitami/cgi-bin
	@${CAT} ${FILESDIR}/xitami.sh.tmpl | ${SED} s:PREFIX:${PREFIX}: > ${WRKDIR}/xitami.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/xitami.sh ${PREFIX}/etc/rc.d/xitami.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xitami/html
	@${INSTALL_MAN} ${WRKSRC}/webpages/xitami/* ${PREFIX}/share/doc/xitami/html
	@${INSTALL_MAN} ${FILESDIR}/default.html ${PREFIX}/xitami/webpages/default.html.sample
.endif

.include <bsd.port.post.mk>
