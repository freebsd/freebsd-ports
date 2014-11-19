# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	queue-repair
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/${PORTNAME}/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Qmail queue diagnostic and repair tool

LICENSE=	GPLv2

USES=		python

OPTIONS_DEFINE=		DOCS QMAIL_PORT
OPTIONS_DEFAULT=	QMAIL_PORT
QMAIL_PORT_DESC=	Depend on qmail port

QMAIL_PORT_USES=	qmail:run

.include <bsd.port.options.mk>

PLIST_FILES=	bin/queue-repair
PORTDOCS=	BLURB CHANGELOG TODO

do-build:
	${REINPLACE_CMD} -e 's,^#!/usr/bin/python,#!${PYTHON_CMD},' \
		${WRKSRC}/queue_repair.py
.if ${PORT_OPTIONS:MQMAIL_PORT}
	${REINPLACE_CMD} -e 's,nofiles,qnofiles,' ${WRKSRC}/queue_repair.py
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py ${STAGEDIR}${PREFIX}/bin/queue-repair
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
