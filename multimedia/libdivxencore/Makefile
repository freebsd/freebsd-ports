# New ports collection makefile for:	libdivxencore
# Date created:		Tue Jan 22 20:06:49 BRST 2002
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdivxencore
PORTVERSION=	0.4.0.50
CATEGORIES=	multimedia
MASTER_SITES=	http://download.projectmayo.com/dnload/divxcore/
PKGNAMESUFFIX=	-devel
DISTNAME=	encore${PORTVERSION:E}src

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	OpenDivX encoding engine from Project Mayo

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-q -a -L
MAKE_ARGS=	LIB_VERSION="${LIB_VERSION}" PREFIX=${PREFIX}
PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/encore/src

LIB_VERSION=	0

.ifndef(NOPROFILE)
PLIST_SUB+=	NOPROFILE=''
.else
PLIST_SUB+=	NOPROFILE='@comment '
.endif

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	@${MKDIR} ${PREFIX}/include/divx

.include <bsd.port.mk>
