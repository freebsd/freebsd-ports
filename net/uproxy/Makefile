# New ports collection makefile for:	uproxy
# Date created:				19 October 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	uproxy
PORTVERSION=	0.91
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/8155/uproxy/
DISTNAME=	${PORTNAME}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Proxy for UDP protocols

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_RC_SUBR=	${PORTNAME}
USE_DOS2UNIX=	${DISTNAME}.c
PORTDOCS=	index.html
PLIST_FILES=	sbin/${PORTNAME}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o t${PORTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/t${PORTNAME} ${PREFIX}/sbin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
