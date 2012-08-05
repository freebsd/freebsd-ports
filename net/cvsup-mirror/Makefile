# New ports collection makefile for:	cvsup-mirror
# Date created:		01 February 1997
# Whom:			jdp
#
# $FreeBSD$
#

PORTNAME=	cvsup-mirror
PORTVERSION=	1.3
PORTREVISION=	8
CATEGORIES=	net
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A kit for easily setting up a FreeBSD mirror site using CVSup

RUN_DEPENDS=	${LOCALBASE}/sbin/cvsupd:${PORTSDIR}/net/cvsup-without-gui

NO_WRKSUBDIR=	true
NO_BUILD=	true
IS_INTERACTIVE=	true
NO_PACKAGE=	too interactive

USE_RC_SUBR=	cvsupd
SUB_FILES=	update.sh

base=${PREFIX}/etc/cvsup
distrib=${base}/sup.client/distrib

.include <bsd.port.pre.mk>

do-extract:
	@test -d ${WRKSRC} || ${MKDIR} ${WRKSRC}

do-install:
	@${ECHO_MSG} "Installing files"
	@test -d ${distrib} || ${MKDIR} ${distrib}
	@${INSTALL_DATA} ${WRKSRC}/config.sh ${base}
	@${INSTALL_DATA} ${WRKSRC}/cvsupd.access ${base}
	@${INSTALL_SCRIPT} ${WRKSRC}/update.sh ${base}
	@${INSTALL_DATA} ${FILESDIR}/supfile ${base}
	@${INSTALL_DATA} ${FILESDIR}/refuse.self ${distrib}
	@${CP} /dev/null ${base}/.start_server

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
