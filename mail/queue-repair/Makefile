# New ports collection makefile for:	queue-repair
# Date created:		22 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	queue-repair
PORTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	http://www.qcc.ca/~charlesc/software/queue_repair/

MAINTAINER=	sergei@kolobov.com

.if !defined(WITHOUT_QMAIL_PORT)
RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail
QMAIL_DIR?=	/var/qmail
.endif

USE_PYTHON=	yes
USE_REINPLACE=	yes

DOCS=		BLURB CHANGELOG TODO docs.txt

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
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
