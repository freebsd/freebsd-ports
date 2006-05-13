# New ports collection makefile for:	disktool
# Date created:			Thu Apr 24 05:10:34 EDT 2003
# Whom:				Serge Gagnon <gagnon__s@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	disktool
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.auxio.org/pub/mirrors/step.polymtl.ca/pub/Xview/apps/disktool/
DISTNAME=	disktool-2.0c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XView sysadmin tool for monitoring diskfull situations

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

ALL_TARGET=	disktool

MAN1=		disktool.1
PLIST_FILES=	bin/disktool

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
EXTRA_PATCHES=	${FILESDIR}/extrapatch-disktool.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/disktool ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/disktool.man \
	${PREFIX}/man/man1/disktool.1

.include <bsd.port.post.mk>
