# New ports collection makefile for:	libdivxdecore developer version
# Date created:		03 Feb 20001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdivxdecore
PORTVERSION=	0.4.0.50
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.projectmayo.com/dnload/divxcore/
PKGNAMESUFFIX=	-devel
DISTNAME=	decore${PORTVERSION:E}src

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	OpenDivX decoding engine from Project Mayo (development version)

ONLY_FOR_ARCHS=	i386
USE_SIZE=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-q -a -L
MAKE_ARGS=	LIB_VERSION="${LIB_VERSION}" PREFIX=${PREFIX}
PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"
INSTALLS_SHLIB=	yes

PATCH_WRKSRC=	${WRKDIR}/decore
WRKSRC=		${WRKDIR}/decore/src

LIB_VERSION=	1

.ifndef(NOPROFILE)
PLIST_SUB+=	NOPROFILE=''
.else
PLIST_SUB+=	NOPROFILE='@comment '
.endif

post-extract:
.for ext in c h
	@${MV} ${WRKSRC}/transferidct.${ext} \
		${WRKSRC}/transferIDCT.${ext}
.endfor
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	@${MKDIR} ${PREFIX}/include/divx

.include <bsd.port.mk>
