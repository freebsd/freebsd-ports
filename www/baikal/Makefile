# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=		baikal
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=		www
MASTER_SITES=	http://baikal-server.com/get/
DISTNAME=		${PORTNAME}-regular-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Lightweight CalDAV/CardDAV server

LICENSE=		GPLv3

USE_PHP=		ctype filter xml pdo_sqlite session mbstring dom

WRKSRC=			${WRKDIR}/${PORTNAME}-regular
NO_BUILD=		yes

SUB_FILES=		pkg-install pkg-message

.include <bsd.port.options.mk>
post-patch:
	${FIND} ${WRKSRC} -type f -not -name '*.php' -exec ${CHMOD} ${SHAREMODE} {} \;
	${FIND} ${WRKSRC} -type f -name '*.php' -exec ${CHMOD} ${BINMODE} {} \;
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	${MV} ${WRKSRC}/Specific/db/db.sqlite \
		${WRKSRC}/Specific/db/db.sqlite-dist
	${CHMOD} 644 ${WRKSRC}/Specific/db/db.sqlite-dist
# I can't decide whether to include this file or forbid it.
# It's probably better to make remote configuration opt-in.
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

	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in INSTALL.md README.md TROUBLESHOOTING.md
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in apache2 nginx
	${INSTALL_DATA} ${WRKSRC}/Specific/virtualhosts/baikal.$f ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
