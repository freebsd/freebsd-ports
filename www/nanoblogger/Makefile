# Created by: ijliao
# $FreeBSD$

PORTNAME=	nanoblogger
PORTVERSION=	3.4.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://nanoblogger.sourceforge.net/downloads/

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Small weblog engine written in Bash for the command line

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/nb
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/nb
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR},g" ${WRKSRC}/nb
	@${REINPLACE_CMD} -e "s,%%DOCSDIR%%,${DOCSDIR},g" ${WRKSRC}/nb
	@${RM} ${WRKSRC}/plugins/page/format/*.orig
	@${RM} ${WRKSRC}/plugins/entry/format/*.orig

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/nb ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/nb.conf ${STAGEDIR}${PREFIX}/etc/nb.conf.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for data in default lang lib moods plugins
	@${MKDIR} ${STAGEDIR}${DATADIR}/${data} && \
		( cd ${WRKSRC}/${data} && \
			${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/${data} "! -name *.orig" )
.endfor
	@${CP} ${WRKSRC}/welcome-to-nb.txt ${STAGEDIR}${DATADIR}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in COPYING ChangeLog README TODO copyright
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/docs/nanoblogger.html ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
