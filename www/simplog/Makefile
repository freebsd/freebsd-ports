# New ports collection makefile for:	simplog
# Date created:		19 April 2004, 21:40 +08:00 (CST)
# Whom:			Jose Liang <jose@jose.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	simplog
PORTVERSION=	0.9.3.4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.9.3.2:src \
		http://www.simplog.org/dl/:update

DISTFILES=	${PORTNAME}-0.9.3.2.tar.gz:src \
		${PORTNAME}_update_only-${PORTVERSION}.tar.gz:update

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete and powerful blogging tool

DATADIR=	${PREFIX}/www/simplog
NO_BUILD=	yes

WRKSRC?=	${WRKDIR}/simplog

do-install:
	@${ECHO} ""
	@${ECHO} "===> Installing simplog"
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -r * ${DATADIR}

post-install:
	@${ECHO} ""
	@${ECHO} "===> Congratulations"
	@${ECHO} "The installation of simplog is complete, please check\
	README in ${DATADIR} first."
	@${ECHO} "For more informations, documentation is available at\
	${DATADIR}/doc/index.php."
	@${ECHO} ""

.include <bsd.port.mk>
