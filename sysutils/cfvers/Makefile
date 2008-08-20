# New ports collection makefile for:	cfvers
# Date created:				2004-10-06
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	cfvers
PORTVERSION=	0.5.4
CATEGORIES=	sysutils devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configuration versioning system

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sqlite/main.py:${PORTSDIR}/databases/py-PySQLite10

USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

MAN1=		cfv.1 cfvadmin.1 cfversd.1
MAN5=		cfvers.conf.5 cfversd.conf.5
DOCS=		AUTHORS NEWS README TODO doc/*.html

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
