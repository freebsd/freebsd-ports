# New ports collection makefile for:	Xitami HTTP Server
# Version required:     2.3d
# Date created:		15 Oct 1997
# Whom:			Ian Vaudrey <i.vaudrey@cableinet.co.uk>
#
# $FreeBSD$
#

DISTNAME=	xiuni23d
PKGNAME=	xitami-2.3d
CATEGORIES=	www
MASTER_SITES=	http://www.imatix.com/pub/xitami/
EXTRACT_SUFX=	.tgz

MAINTAINER=	i.vaudrey@cableinet.co.uk

NO_WRKSUBDIR=	yes

do-build:
	@${CHMOD} +x ${WRKSRC}/xibuild
	@${SETENV} TOPDIR=${WRKSRC} ${SH} ${WRKSRC}/xibuild

do-install:
	@${MKDIR} ${PREFIX}/xitami/cgi-bin
	@${MKDIR} ${PREFIX}/xitami/webpages
	@${CAT} ${FILESDIR}/defaults.cfg.tmpl | ${SED} s:PREFIX:${PREFIX}: > ${WRKDIR}/defaults.cfg
	@${INSTALL_DATA} ${WRKDIR}/defaults.cfg ${PREFIX}/xitami
	@${INSTALL_DATA} ${FILESDIR}/xitami.aut ${PREFIX}/xitami
	@${CHMOD} u+w ${PREFIX}/xitami/*
	@${INSTALL_DATA} ${WRKSRC}/src/smt/xitami.cfg ${PREFIX}/xitami
	@${INSTALL_PROGRAM} ${WRKSRC}/src/smt/xitami ${PREFIX}/xitami
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/testcgi ${PREFIX}/xitami/cgi-bin
	@${CAT} ${FILESDIR}/xitami.sh.tmpl | ${SED} s:PREFIX:${PREFIX}: > ${WRKDIR}/xitami.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/xitami.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xitami/html
	@${INSTALL_MAN} ${WRKSRC}/webpages/xitami/* ${PREFIX}/share/doc/xitami/html
	@${INSTALL_MAN} ${FILESDIR}/default.html ${PREFIX}/xitami/webpages
.endif

.include <bsd.port.mk>
