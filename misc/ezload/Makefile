# New ports collection makefile for:	ezload
# Date created:		18 november 1999
# Whom:			n_hibma
#
# $FreeBSD$
#

PORTNAME=	ezload
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://proj.bpsw.biz/ezload/downloads/

MAINTAINER=	bahamasfranks@gmail.com
COMMENT=	Firmware down/uploader for Cypress' EZ-USB chip

MAN1=		ezupload.1 ezdownload.1 aw.1
MANCOMPRESSED=	yes

MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man/man" MKDIR="${MKDIR}" INSTALL_DATA="${INSTALL_DATA}" FORCE="${FORCE}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
