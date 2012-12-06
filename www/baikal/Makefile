# $FreeBSD$
# Created by:	Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=		baikal
PORTVERSION=	0.2.4
CATEGORIES=		www
MASTER_SITES=	http://baikal.codr.fr/get/
DISTNAME=		${PORTNAME}-regular-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Lightweight CalDAV/CardDAV server

USE_PHP=		ctype filter xml pdo_sqlite

WRKSRC=			${WRKDIR}/${PORTNAME}-regular
NO_BUILD=		yes

PLIST_SUB+=		CALDB="${WWWDIR}/Specific/db/db.sqlite"
SUB_LIST+=		CALDB="${WWWDIR}/Specific/db/db.sqlite"
SUB_FILES=		pkg-install pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS=		*
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

post-patch:
	${FIND} ${WRKSRC} -type f \! -name '*.php' -exec ${CHMOD} ${SHAREMODE} {} \;
	${FIND} ${WRKSRC} -type f -name '*.php' -exec ${CHMOD} ${BINMODE} {} \;
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	${MV} ${WRKSRC}/Specific/db/db.sqlite \
		${WRKSRC}/Specific/db/db.sqlite-dist
	${CHMOD} 644 ${WRKSRC}/Specific/db/db.sqlite-dist
# I can't decide whether to include this file or forbid it.
#	${ECHO_CMD} "platypus" > ${WRKSRC}/Specific/ENABLE_INSTALL
	${RM} ${WRKSRC}/Specific/ENABLE_INSTALL
	${REINPLACE_CMD} -e 's,/var/www/dav.mydomain.com,${WWWDIR},g' \
		${WRKSRC}/Specific/virtualhosts/baikal.*

do-install:
	${MKDIR} ${WWWDIR}
.for DIR in Core html Specific
	cd ${WRKSRC} && ${FIND} ${DIR} \! -path '*/virtualhosts*' | \
		${CPIO} -pdmu -R ${WWWOWN}:${WWWGRP} --quiet ${WWWDIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
.for f in INSTALL.md LICENSE.txt README.md TROUBLESHOOTING.md
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
.for f in apache2 nginx
	${INSTALL_DATA} ${WRKSRC}/Specific/virtualhosts/baikal.$f ${EXAMPLESDIR}
.endfor
.endif

post-install:
	@${SH} ${PKGINSTALL} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
