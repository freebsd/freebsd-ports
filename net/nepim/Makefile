# New ports collection makefile for:	nepim
# Date created:				19th September 2005
# Whom:					Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	nepim
PORTVERSION=	0.15
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://www.yazzy.org/ports/
MASTER_SITE_SUBDIR=	nepim

MAINTAINER=	yazzy@yazzy.org
COMMENT=	Tool for measuring available bandwidth between hosts

LIB_DEPENDS=	oop.4:${PORTSDIR}/devel/liboop

USE_GMAKE=	yes
ALL_TARGET=	default

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	bin/nepim

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nepim ${PREFIX}/bin

.include <bsd.port.mk>
