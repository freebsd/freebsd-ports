# New ports collection makefile for:	ezload
# Version required:	0.2
# Date created:		14 august 1999
# Whom:			n_hibma
#
# $FreeBSD$
#

DISTNAME=	ezload-0.2
CATEGORIES=	misc
MASTER_SITES=	http://www.etla.net/~n_hibma/usb/

MAINTAINER=	n_hibma@FreeBSD.ORG

MAN8=		ezupload.8 ezdownload.8 aw.8
MANCOMPRESSED=	yes

MAKE_ENV=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
IGNORE=	'This port only works on 4.x+'
.endif

.include <bsd.port.post.mk>
