# New ports collection makefile for:	ezload
# Date created:		18 november 1999
# Whom:			n_hibma
#
# $FreeBSD$
#

PORTNAME=	ezload
PORTVERSION=	0.3.1
CATEGORIES=	misc
MASTER_SITES=	http://www.etla.net/~n_hibma/usb/

MAINTAINER=	n_hibma@FreeBSD.ORG

MAN1=		ezupload.1 ezdownload.1 aw.1
MANCOMPRESSED=	yes

MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man/man" MKDIR="${MKDIR}" INSTALL_DATA="${INSTALL_DATA}" FORCE="${FORCE}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400012
IGNORE=		'This port only works on 4.00012'
.endif

.include <bsd.port.post.mk>
