# New ports collection makefile for:	simplog
# Date created:		19 April 2004, 21:40 +08:00 (CST)
# Whom:			Jose Liang <jose@jose.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	simplog
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A complete and powerful blogging tool

DATADIR=	${PREFIX}/www/simplog
NO_BUILD=	yes

WRKSRC?=	${WRKDIR}/simplog

do-install:
	@${ECHO} ""
	@${ECHO} "===> Installing simplog"
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -R adodb doc images install templates * \
	${DATADIR}

post-install:
	@${ECHO} ""
	@${ECHO} "===> Congratulations"
	@${ECHO} "The installation of simplog is complete, please check\
	README in ${DATADIR} first."
	@${ECHO} "For more informations, documentation is available at\
	${DATADIR}/doc/index.php."

.include <bsd.port.mk>
