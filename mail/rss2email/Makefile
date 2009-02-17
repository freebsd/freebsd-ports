# New ports collection makefile for:	rss2email
# Date created:		17 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rss2email
PORTVERSION=	2.61
CATEGORIES=	mail python
MASTER_SITES=	CENKES
# http://rss2email.infogami.com/rss2email.py

MAINTAINER=	chifeng@gmail.com
COMMENT=	Read newsfeeds in your email client

RUN_DEPENDS=	py*-feedparser>=0:${PORTSDIR}/textproc/py-feedparser \
		py*-html2text>=0:${PORTSDIR}/textproc/py-html2text

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
MAN1=		r2e.1
PLIST_FILES=	bin/r2e %%DATADIR%%/${PORTNAME}.py
PLIST_DIRS=	%%DATADIR%%
PORTEXAMPLES=	config.py

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHONCMD@|${PYTHON_CMD}|;s|@DATADIR@|${DATADIR}|'\
		${WRKSRC}/r2e

do-install:
	@${INSTALL} -d ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/r2e ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/r2e.1 ${MAN1PREFIX}/man/man1/
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/config.py ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
