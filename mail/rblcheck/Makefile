# New ports collection makefile for:	rblcheck
# Date created:		28 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	rblcheck
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

post-configure:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.rbl
.if !defined(BATCH)
	@${ECHO} "NOTE: You can pre-compile your own sites into rblcheck by"
	@${ECHO} "      creating ${WRKDIRPREFIX}${.CURDIR}/local.sites.  The"
	@${ECHO} "      format of this file is:"
	@${ECHO}
	@${ECHO} "             SITE(\"my.rbl.site\")"
	@${ECHO} "             SITE(\"another.rbl.site\")"
.endif

pre-build:
.if exists(${WRKDIRPREFIX}${.CURDIR}/local.sites)
	${CAT} ${WRKDIRPREFIX}${.CURDIR}/local.sites >> ${WRKSRC}/rblsites.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rblcheck
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/rblcheck
.endif

.include <bsd.port.mk>
