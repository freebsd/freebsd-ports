# New ports collection makefile for:	rfstool
# Date created:				2005-03-02
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	rfstool
PORTVERSION=	0.14
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	rfstool-0.14-source

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Read from a Reiser file system

PLIST_FILES=	bin/rfstool
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/rfstool-0.14/RFSTOOL

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500035
MAKEFILE=	makefile.gcc3x
.else
MAKEFILE=	makefile.gcc2x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rfstool ${PREFIX}/bin

.include <bsd.port.post.mk>
