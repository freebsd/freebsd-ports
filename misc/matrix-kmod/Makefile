# New ports collection makefile for:	strijar
# Date created:				22 Dec 2000
# Whom:					Oleg Belousov <strijar@urai.ru>
#
# $FreeBSD$
#

PORTNAME=	matrix
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.belousov.com/download/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	strijar@urai.ru
COMMENT=	Screensaver for console (matrix_saver.ko) "Matrix" like

KMODDIR=	${PREFIX}/modules

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Need FreeBSD 4.0 or above"
.endif

do-install:
	@${MKDIR} ${KMODDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/matrix_saver.sh ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/*.ko ${KMODDIR}

.include <bsd.port.post.mk>
