# New ports collection makefile for:	cvsup-mirror
# Date created:		01 February 1997
# Whom:			jdp
#
# $FreeBSD$
#

PORTNAME=	cvsup-mirror
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	net
DISTFILES=

MAINTAINER=	jdp@FreeBSD.org
COMMENT=	A kit for easily setting up a FreeBSD mirror site using CVSup

RUN_DEPENDS=	${LOCALBASE}/sbin/cvsupd:${PORTSDIR}/net/cvsup-without-gui

NO_WRKSUBDIR=	true
NO_BUILD=	true
IS_INTERACTIVE=	true
NO_PACKAGE=	too interactive
SCRIPTS_ENV=	USA_RESIDENT=${USA_RESIDENT}

base=${PREFIX}/etc/cvsup
distrib=${base}/sup.client/distrib
rc=${PREFIX}/etc/rc.d

do-extract:
	@test -d ${WRKSRC} || ${MKDIR} ${WRKSRC}

do-install:
	@${ECHO_MSG} "Installing files"
	@test -d ${distrib} || ${MKDIR} ${distrib}
	@test -d ${rc} || ${MKDIR} ${rc}
	@${INSTALL_DATA} ${WRKSRC}/config.sh ${base}
	@${INSTALL_DATA} ${WRKSRC}/cvsupd.access ${base}
	@${INSTALL_SCRIPT} ${FILESDIR}/update.sh ${base}
	@${INSTALL_DATA} ${FILESDIR}/supfile ${base}
	@${INSTALL_DATA} ${FILESDIR}/refuse.self ${distrib}
	@${INSTALL_SCRIPT} ${FILESDIR}/cvsupd.sh ${rc}
	@${CP} /dev/null ${base}/.start_server

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
