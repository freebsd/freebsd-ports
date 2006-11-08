# New ports collection makefile for:	uproxy
# Date created:				19 October 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	uproxy
PORTVERSION=	0.91
CATEGORIES=	net
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/8155/uproxy/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@logvinov.com
COMMENT=	Proxy for UDP protocols

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_RC_SUBR=	${PORTNAME}
PORTDOCS=	index.html
PLIST_FILES=	sbin/${PORTNAME}

pre-patch:
	@${CAT} ${WRKSRC}/${DISTNAME}.c | ${SED} "s/`printf '\r'`//" > ${WRKSRC}/${DISTNAME}.c

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
