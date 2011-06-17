# ex:ts=8
# Ports collection makefile for:	subconv
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	subconv
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.linux-projects.net/d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts DivX subtitles from one format to another

DEPRECATED=	Look like an abandonware, no more public distifles
EXPIRATION_DATE=	2011-08-01

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_PYTHON=	yes

PORTDOCS=	README
PLIST_FILES=	bin/subconv

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/subconv ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
