# New ports collection makefile for:	simplog
# Date created:		19 April 2004, 21:40 +08:00 (CST)
# Whom:			Jose Liang <jose@jose.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	simplog
PORTVERSION=	0.9
CATEGORIES=	www
MASTER_SITES=	ftp://jose.idv.tw/simplog/

MAINTAINER=	jose@jose.idv.tw
COMMENT=	A complete and powerful blogging tool

DATADIR=	${PREFIX}/www/simplog
NO_BUILD=	yes
USE_APACHE=	yes
USE_PHP=	yes

WRKSRC?=	${WRKDIR}/simplog

do-install:
	@${ECHO} " "
	@${ECHO} "**************************"
	@${ECHO} "*** Installing simplog ***"
	@${ECHO} "**************************"
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -R templates install images doc cache adodb * \
	${DATADIR}

post-install:
	@${ECHO} " "
	@${ECHO} "*************************"
	@${ECHO} "**** Congratulations ****"
	@${ECHO} "*************************"
	@${ECHO} "The installation of simplog is complete, please check\
	README in ${DATADIR} first."
	@${ECHO} "For more informations, documentation is available at\
	${DATADIR}/doc/index.php."

.include <bsd.port.mk>
