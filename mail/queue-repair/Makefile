# New ports collection makefile for:	queue-repair
# Date created:		22 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	queue-repair
PORTVERSION=	0.9.0
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	A qmail queue diagnostic and repair tool

.if !defined(WITHOUT_QMAIL_PORT)
RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail
QMAIL_DIR?=	/var/qmail
.endif

USE_PYTHON=	yes
USE_REINPLACE=	yes

DOCS=		BLURB CHANGELOG TODO

do-build:
	${REINPLACE_CMD} -e 's,^#!/usr/bin/python,#!${PYTHON_CMD},' \
		${WRKSRC}/queue_repair.py
.if !defined(WITHOUT_QMAIL_PORT)
	${REINPLACE_CMD} -e 's,nofiles,qnofiles,' ${WRKSRC}/queue_repair.py
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py ${PREFIX}/bin/queue-repair
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
