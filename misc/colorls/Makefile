# New ports collection makefile for:	colorls
# Version required:	FreeBSD-current (around March '95)
# Date created:		8 March 1995
# Whom:			Satoshi Asami
#
# $Id$
#
DISTNAME=	colorls
DISTFILES=	ls.tar.gz
FTP_SITE=	ftp.freebsd.org
FTP_DIR=	/pub/FreeBSD/FreeBSD-current/src/bin/
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/FreeBSD-current/src/bin/
WRKSRC=		${WRKDIR}/ls

.if !defined(MASTER_SITE_OVERRIDE)
fetch: pre-fetch
	@if [ ! -d ${DISTDIR} ]; then mkdir -p ${DISTDIR}; fi
	@(cd ${DISTDIR}; \
	  if [ ! -f ${DISTFILES} ]; then \
	    (sleep 5; echo "cd ${FTP_DIR}"; echo "get ${DISTFILES}") | ${NCFTP} ${NCFTPFLAGS} ${FTP_SITE}; \
	  fi \
	)
.endif

.include <bsd.port.mk>
