# New ports collection makefile for:	ezload
# Date created:		18 november 1999
# Whom:			n_hibma
#
# $FreeBSD$
#

PORTNAME=	ezload
PORTVERSION=	0.4.0
CATEGORIES=	misc
MASTER_SITES=	http://proj.bpsw.biz/ezload/downloads/

MAINTAINER=	mcampos@bpsw.biz
COMMENT=	Firmware down/uploader for Cypress' EZ-USB chip

MAN1=		ezupload.1 ezdownload.1 aw.1
MANCOMPRESSED=	yes

MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man/man" MKDIR="${MKDIR}" INSTALL_DATA="${INSTALL_DATA}" FORCE="${FORCE}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 460000
IGNORE=		'This port only works on FreeBSD 4.6.0+'
.endif

.include <bsd.port.post.mk>
