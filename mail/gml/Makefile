# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gml
PORTVERSION=	0.4
CATEGORIES=	mail
MASTER_SITES=	http://marklyon.org/wp-content/uploads/2013/01/ \
		LOCAL/glarkin
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mbox & Maildir to Gmail loader

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		dos2unix python:2,run
PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|.exe||g' \
		-e 's|"c:\\mail\\Inbox.*"|/home/user/Inbox|g' ${WRKDIR}/*

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
