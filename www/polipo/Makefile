# Created by: Frank Behrens <frank@pinky.sax.de>
# $FreeBSD$

PORTNAME=	polipo
PORTVERSION=	1.0.4.1
CATEGORIES=	www
MASTER_SITES=	http://freehaven.net/~chrisd/polipo/ \
		http://www.sax.de/~frank/polipo4bsd/files/

MAINTAINER=	frank@pinky.sax.de
COMMENT=	Small and fast caching web proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo
USE_RC_SUBR=	polipo

INFO=		polipo

.include <bsd.port.pre.mk>

DOCSDIR=	${DATADIR}/www/doc
PORTDOCS=	*

SUB_FILES=	pkg-message pkg-install pkg-deinstall 400.polipo
SUB_LIST+=	USER=${PUSER} GROUP=${PGRP} DESTDIR=${DESTDIR} PCONFIGDIR=${PCONFIGDIR} \
		PCACHEDIR=${PCACHEDIR} PPIDDIR=${PPIDDIR} PPIDFILE=${PPIDFILE} \
		PLOGFILE=${PLOGFILE}

# polipo installation options, propagated to install scripts
PUSER?=		polipo
PGRP?=		polipo
PCONFIGDIR?=	${PREFIX}/etc/polipo/
PCACHEDIR?=	/var/cache/polipo
PPIDDIR?=	/var/run/polipo/
PPIDFILE=	${PPIDDIR}polipo.pid
PLOGFILE?=	/var/log/polipo
MAKE_ENV+=	DISK_CACHE_ROOT=${PCACHEDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/polipo ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_SCRIPT} ${WRKDIR}/400.polipo ${STAGEDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_MAN} ${WRKSRC}/polipo.man ${STAGEDIR}${PREFIX}/man/man1/polipo.1
	${MKDIR} ${STAGEDIR}${PCONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/config.sample ${WRKSRC}/forbidden.sample ${STAGEDIR}${PCONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/polipo.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/localindex.html ${STAGEDIR}${DATADIR}/www/index.html

post-install:
	${MKDIR} ${STAGEDIR}${PCACHEDIR}

.include <bsd.port.post.mk>
