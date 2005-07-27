# New ports collection makefile for:   polipo
# Date created:        2005-01-25
# Whom:                Frank Behrens <frank@pinky.sax.de>
#
# $FreeBSD$
#

PORTNAME=	polipo
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.pps.jussieu.fr/~jch/software/files/polipo/ \
		http://www.sax.de/~frank/polipo4bsd/files/

MAINTAINER=	frank@pinky.sax.de
COMMENT=	A small and fast caching web proxy

MAN1=		polipo.1

USE_RC_SUBR=	polipo.sh

.include <bsd.port.pre.mk>

# in some 4.x makeinfo does not work. So we do not try to build and install.
.if ${OSVERSION} < 500000
NO_PTEXINFO=	yes
.endif
.if defined(NO_PTEXINFO)
ALL_TARGET=	polipo
NOPORTDOCS=	yes
.else
INFO=		polipo
.endif

DOCSDIR=	${DATADIR}/www/doc
PORTDOCS=	*

SUB_FILES=	pkg-message pkg-install pkg-deinstall 400.polipo
SUB_LIST+=	USER=${PUSER} GROUP=${PGRP} DESTDIR=${DESTDIR} PCONFIGDIR=${PCONFIGDIR} \
		PCACHEDIR=${PCACHEDIR} PPIDDIR=${PPIDDIR} PPIDFILE=${PPIDFILE} \
		PLOGFILE=${PLOGFILE} RC_SUBR=${RC_SUBR}

# polipo installation options, propagated to install scripts
PUSER?=		polipo
PGRP?=		polipo
PCONFIGDIR?=	${PREFIX}/etc/polipo/
PCACHEDIR?=	/var/cache/polipo
PPIDDIR?=	/var/run/polipo/
PPIDFILE=	${PPIDDIR}polipo.pid
PLOGFILE?=	/var/log/polipo
MAKE_ENV+=	DISK_CACHE_ROOT=${PCACHEDIR}

pre-install: apply-slist
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/polipo ${DESTDIR}${PREFIX}/bin/
	${MKDIR} ${DESTDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_SCRIPT} ${WRKDIR}/400.polipo ${DESTDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_MAN} ${WRKSRC}/polipo.man ${DESTDIR}${PREFIX}/man/man1/polipo.1
	${MKDIR} ${DESTDIR}${PCONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/config.sample ${DESTDIR}${PCONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/forbidden.sample ${DESTDIR}${PCONFIGDIR}
	${CHGRP} -R ${PGRP} ${DESTDIR}${PCONFIGDIR}
.if !defined(NO_PTEXINFO)
	${INSTALL_DATA} ${WRKSRC}/polipo.info ${DESTDIR}${PREFIX}/info/
	install-info ${PREFIX}/info/polipo.info ${DESTDIR}${PREFIX}/info/dir
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/localindex.html ${DESTDIR}${DATADIR}/www/index.html
	${CHGRP} -R ${PGRP} ${DESTDIR}${DATADIR}
.endif

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
