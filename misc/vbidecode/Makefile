# New ports collection makefile for:	vbidecode
# Date created:		Mon June 7 16:11:00 BST 1999
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#
# Note: vbidecode is one part of the bttv distribution, the Linux bt848 driver
# It therefore has a DISTNAME of bttv but a PORTNAME of vbidecode

PORTNAME=		vbidecode
PORTVERSION=		1.1.3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	roger
DISTNAME=		bttv-0.6.4

MAINTAINER=		roger@freebsd.org
COMMENT=	Get Videotext/Teletext (.vtx) and other VBI data from TV channels

PLIST_FILES=		bin/vbidecode
WRKSRC=			${WRKDIR}/bttv/apps/vbidecode

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vbidecode ${PREFIX}/bin
	@${STRIP_CMD} ${PREFIX}/bin/vbidecode

.include <bsd.port.post.mk>
