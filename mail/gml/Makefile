# New ports collection makefile for:	gml
# Date created:				23 March 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	gml
PORTVERSION=	0.4
CATEGORIES=	mail
MASTER_SITES=	http://marklyon.org/gmail/old/ \
		LOCAL/glarkin
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Mbox & Maildir to Gmail loader

USE_PYTHON_RUN=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_DOS2UNIX=	yes
PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|.exe||g' \
		-e 's|"c:\\mail\\Inbox.*"|/home/user/Inbox|g' ${WRKDIR}/*

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
