# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=		baikal
PORTVERSION=	0.2.6
CATEGORIES=		www
MASTER_SITES=	http://baikal-server.com/get/
DISTNAME=		${PORTNAME}-regular-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Lightweight CalDAV/CardDAV server

LICENSE=		GPLv3

USE_PHP=		ctype filter xml pdo_sqlite session mbstring dom

WRKSRC=			${WRKDIR}/${PORTNAME}-regular
NO_BUILD=		yes

PLIST_SUB+=		CALDB="${WWWDIR}/Specific/db/db.sqlite"
SUB_LIST+=		CALDB="${WWWDIR}/Specific/db/db.sqlite"
SUB_FILES=		pkg-install pkg-message

PORTDOCS=		*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>
post-patch:
	${FIND} ${WRKSRC} -type f -not -name '*.php' -exec ${CHMOD} ${SHAREMODE} {} \;
	${FIND} ${WRKSRC} -type f -name '*.php' -exec ${CHMOD} ${BINMODE} {} \;
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	${MV} ${WRKSRC}/Specific/db/db.sqlite \
		${WRKSRC}/Specific/db/db.sqlite-dist
	${CHMOD} 644 ${WRKSRC}/Specific/db/db.sqlite-dist
# I can't decide whether to include this file or forbid it.
#	${ECHO_CMD} "platypus" > ${WRKSRC}/Specific/ENABLE_INSTALL
	${RM} -f ${WRKSRC}/Specific/ENABLE_INSTALL
	${REINPLACE_CMD} -e 's,/var/www/dav.mydomain.com,${WWWDIR},g' \
		${WRKSRC}/Specific/virtualhosts/baikal.*

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
.for DIR in Core html vendor
	cd ${WRKSRC} && ${FIND} ${DIR} | \
		${CPIO} -pdmu -R ${BINOWN}:${BINGRP} --quiet ${STAGEDIR}${WWWDIR}
.endfor
	cd ${WRKSRC} && ${FIND} Specific -not -path '*/virtualhosts*' | \
		${CPIO} -pdmu -R ${WWWOWN}:${WWWGRP} --quiet ${STAGEDIR}${WWWDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in INSTALL.md LICENSE.txt README.md TROUBLESHOOTING.md
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in apache2 nginx
	${INSTALL_DATA} ${WRKSRC}/Specific/virtualhosts/baikal.$f ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
