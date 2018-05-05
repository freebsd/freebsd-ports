# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	artwiz-fonts
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://kobyla.info/soft/distfiles/ \
		LOCAL/garga/artwiz/
DISTNAME=	${PORTNAME}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Set of free fonts for X11 desktops

NO_BUILD=	yes
USES=		fonts tar:bzip2
WRKSRC=		${WRKDIR}/fluxbox-${PORTNAME}

FONTS=		anorexia aqui cure cursor drift edges gelly glisp-bold \
		glisp lime mints-mild mints-strong nu snap

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
