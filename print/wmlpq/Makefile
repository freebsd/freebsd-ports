# New ports collection makefile for:	wmlpq
# Date created:				Thu Jul  5 14:43:55 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmlpq
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	print windowmaker
MASTER_SITES=	http://www.ur.uklinux.net/wmlpq/dl/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print queue monitoring dockapp for Window Maker

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XORG=	xpm

MAN1=		${PORTNAME}.1x

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1x ${PREFIX}/man/man1
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/sample.wmlpqrc ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/wmlpqrc ${PREFIX}/share/examples/${PORTNAME}
.endif #NOPORTDOCS
	@${SED} -e "s|/usr/X11R6|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
