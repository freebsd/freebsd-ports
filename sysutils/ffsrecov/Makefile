# New ports collection makefile for:	ffsrecov
# Date created:        4 May 1999
# Whom:                jmg
#
# $FreeBSD$
#

PORTNAME=	ffsrecov
PORTVERSION=	0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recover files from a corrupt FFS

MAN8=		ffsrecov.8
PLIST_FILES=	bin/ffsrecov

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
BROKEN=		"Incompatible with UFS2 header files"
.endif

.include <bsd.port.post.mk>
