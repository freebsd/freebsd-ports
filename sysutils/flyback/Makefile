# New ports collection makefile for:	flyback
# Date created:		2008-01-20
# Whom:			Lars Engels <lme@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flyback
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A backup frontend like Apple's Time Machine

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
USE_GNOME=	pygtk2 pygnome2 libglade2

.include <bsd.port.pre.mk>

SUB_FILES=	flyback.sh

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/GPL.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/viewer.glade ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/flyback.sh ${PREFIX}/bin/flyback

.include <bsd.port.post.mk>
