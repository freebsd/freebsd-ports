# New ports collection makefile for:	vietunicode-hannom
# Date created:		2007/01/06
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	vietunicode-hannom
PORTVERSION=	2005.02.06
PORTREVISION=	1
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	SF/vietunicode/hannom/hannom%20v2005
DISTNAME=	hannom

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UNICODE Han Nom Font Set

USE_ZIP=	yes
DIST_SUBDIR=	VietUnicode
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TTF=		HAN_NOM_A.ttf HAN_NOM_B.ttf

post-patch:
	@${MV} ${WRKSRC}/HAN\ NOM\ A.ttf ${WRKSRC}/HAN_NOM_A.ttf
	@${MV} ${WRKSRC}/HAN\ NOM\ B.ttf ${WRKSRC}/HAN_NOM_B.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${FONTSDIR}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
