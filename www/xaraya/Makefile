# New ports collection makefile for:	xaraya
# Date created:		2005-07-10
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#
# Try to specify WITH_PGSQL to use pgsql php extension. Mysql
# extension would be used by default.

PORTNAME=	xaraya
PORTVERSION=	1.0.0r3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-1.0.0-rc3-base

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Framework to create fully dynamic Content Mangement Solutions

.if defined(WITH_PGSQL)
USE_PHP=	pgsql
.else
USE_PHP=	mysql
.endif
BROKEN_WITH_PHP=	5
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-1.0.0-rc3

# May user to override this
XARAYADIR?=	www/xaraya

pre-install:
	@${RM} -f ${TMPPLIST}

do-install:
	${MKDIR} ${PREFIX}/${XARAYADIR}
	${CP} -r ${WRKSRC}/html/* ${PREFIX}/${XARAYADIR}
.if !defined(NOTOOLS)
	${MKDIR} ${DATADIR}
	${CP} -r ${WRKSRC}/tools ${DATADIR}
.endif
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${XARAYADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${DOCSDIR}
	${CP} ${WRKSRC}/INSTALL.txt ${WRKSRC}/LICENSE.txt \
		${WRKSRC}/CREDITS.txt ${DOCSDIR}
.endif

# Create plist
post-install:
	@${FIND} ${PREFIX}/${XARAYADIR} ! -type d -and ! -name install.php \
		-and ! -name upgrade.php | ${SED} -e \
		's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${XARAYADIR} -type f -and '(' -name install.php \
		-or -name upgrade.php ')' | ${SED} -e \
		's,^${PREFIX}/\(.*\),@unexec rm -f %D/\1 >/dev/null 2>\&1 || true,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${XARAYADIR} -type d -and -path "*var*" | \
		${SED} -e 's,^${PREFIX}/\(.*\),@unexec rmdir %D/\1 >/dev/null 2>\&1 || true,' | \
		${SORT} -r >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${XARAYADIR} -type d -and ! -path "*var*" | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' | \
		${SORT} -r >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${FIND} ${DOCSDIR} ! -type d | ${SED} -e \
		's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type d | ${SED} -e \
		's,^${PREFIX}/,@dirrm ,' | \
		${SORT} -r >> ${TMPPLIST}
.endif
.if !defined(NOTOOLS)
	@${FIND} ${DATADIR} ! -type d | ${SED} -e \
		's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SED} -e \
		's,^${PREFIX}/,@dirrm ,' | \
		${SORT} -r >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
