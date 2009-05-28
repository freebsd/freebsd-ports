# New ports collection makefile for:	netstiff
# Date created:				23 March 2007
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	netstiff
PORTVERSION=	20080331
CATEGORIES=	www
MASTER_SITES=	http://pkqs.net/~sbeyer/tools/netstiff/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A powerful web page update checker

NO_BUILD=	yes
USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
PORTDOCS=	ChangeLog LICENSE THANKSTO
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/ruby|${RUBY}|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
