# ports collection Makefile for: nctop
# Date created:		01 August 2005
# Whom:			Ralf Becker <nctop@web.de>
#
# $FreeBSD$
#

PORTNAME=	nctop
PORTVERSION=	0.23.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rz.uni-karlsruhe.de/~hj28/download.php?file=/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A remote system monitor for unix hosts

USE_BZIP2=	YES

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-libwrap     \
		--with-setgid=kmem

MAN1=		nctopd.1 nctop.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900006
EXTRA_PATCHES=	${FILESDIR}/utmpx-machine.c
.endif

.include <bsd.port.post.mk>
