# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	baikal
PORTVERSION=	0.2.7
CATEGORIES=	www
MASTER_SITES=	http://baikal-server.com/get/ LOCAL/mat/${PORTNAME}
DISTNAME=	${PORTNAME}-regular-${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Lightweight CalDAV/CardDAV server

LICENSE=	GPLv3

USES=	tar:tgz
USE_PHP=	ctype filter xml pdo_sqlite session mbstring dom

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}-regular
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>
post-patch:
	${MV} ${WRKSRC}/Specific/db/db.sqlite \
		${WRKSRC}/Specific/db/db.sqlite.sample
	${RM} -f ${WRKSRC}/Specific/ENABLE_INSTALL
	${REINPLACE_CMD} -e 's,/var/www/dav.mydomain.com,${WWWDIR},g' \
		${WRKSRC}/Specific/virtualhosts/baikal.*

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DIR in Core html vendor Specific
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${WWWDIR}
.endfor
.for f in INSTALL.md README.md TROUBLESHOOTING.md
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	${MV} ${STAGEDIR}${WWWDIR}/Specific/virtualhosts ${STAGEDIR}${EXAMPLESDIR}
	${RM} -f ${STAGEDIR}${EXAMPLESDIR}/*.bak

.include <bsd.port.mk>
