# New ports collection makefile for:	Xitami HTTP Server
# Date created:		15 Oct 1997
# Whom:			Ian Vaudrey <i.vaudrey@cableinet.co.uk>
#
# $FreeBSD$
#

PORTNAME=	xitami
PORTVERSION=	2.5c2
CATEGORIES=	www
MASTER_SITES=	http://www.xitami.com/
DISTNAME=	xiopen_2_5_src

MAINTAINER=	bdluevel@heitec.net
COMMENT=	A fast, portable multithreaded web server

NO_WRKSUBDIR=	yes

MAN8=	xitami.8

SUB_FILES=	defaults.cfg	\
			xitami.8

USE_RC_SUBR=	xitami.sh

.include <bsd.port.pre.mk>

do-build:
	${MAKE} -C ${WRKSRC}/sfl
	${MAKE} -C ${WRKSRC}/gsl
	${MAKE} -C ${WRKSRC}/smt
	${MAKE} -C ${WRKSRC}/studio
	${MAKE} -C ${WRKSRC}/xiadmin
	${MAKE} -C ${WRKSRC}/xiopen

do-install:
	${MKDIR} ${PREFIX}/etc/xitami
	${INSTALL_DATA} ${WRKDIR}/defaults.cfg ${PREFIX}/etc/xitami/defaults.cfg.sample
	${INSTALL_DATA} ${FILESDIR}/xitami.aut ${PREFIX}/etc/xitami
	${INSTALL_DATA} ${WRKSRC}/xiopen/xitami.cfg ${PREFIX}/etc/xitami
	${INSTALL_DATA} ${WRKSRC}/xiopen/pipedef.xml ${PREFIX}/etc/xitami
	${INSTALL_DATA} ${FILESDIR}/dir.gsl ${PREFIX}/etc/xitami
	${INSTALL_PROGRAM} ${WRKSRC}/xiopen/xitami ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/xitami.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/xiopen/webpages/xitami/* ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
