# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rss2email
PORTVERSION=	2.70
CATEGORIES=	mail python
MASTER_SITES=	http://www.allthingsrss.com/rss2email/

MAINTAINER=	chifeng@gmail.com
COMMENT=	Read newsfeeds in your email client

RUN_DEPENDS=	py*-feedparser>=0:${PORTSDIR}/textproc/py-feedparser \
		py*-html2text>=0:${PORTSDIR}/textproc/py-html2text

USE_PYTHON=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/r2e %%DATADIR%%/${PORTNAME}.py
PLIST_DIRS=	%%DATADIR%%
PORTEXAMPLES=	config.py.example

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHONCMD@|${PYTHON_CMD}|;s|@DATADIR@|${DATADIR}|'\
		${WRKSRC}/r2e
	@${REINPLACE_CMD} -e "s|\([^[:alnum:]]\)c.type\([^[:alnum:]]\)|\1c.get('type','')\2|"\
		${WRKSRC}/rss2email.py

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/r2e ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.py.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
