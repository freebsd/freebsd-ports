# New ports collection makefile for:	xaraya
# Date created:		2005-07-10
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#
# Try to specify WITH_PGSQL to use pgsql php extension. Mysql
# extension would be used by default.

PORTNAME=	xaraya
PORTVERSION=	1.2.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Core%20plus%20Modules/Xaraya%20${PORTVERSION}%20Core%20Plus
DISTNAME=	${PORTNAME}-${PORTVERSION}-base

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Framework to create fully dynamic Content Management Solutions

.if defined(WITH_PGSQL)
USE_PHP=	pgsql
.else
USE_PHP=	mysql
.endif
USE_PHP+=	pcre xml
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# May user to override this
XARAYADIR?=	www/xaraya

pre-install:
	@${RM} -f ${TMPPLIST}

do-install:
	${MKDIR} ${PREFIX}/${XARAYADIR}
	${CP} -R ${WRKSRC}/html/* ${PREFIX}/${XARAYADIR}
.if !defined(NOTOOLS)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/tools/* ${EXAMPLESDIR}
.endif
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${XARAYADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
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
	@${FIND} ${EXAMPLESDIR} ! -type d | ${SED} -e \
		's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SED} -e \
		's,^${PREFIX}/,@dirrm ,' | \
		${SORT} -r >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
