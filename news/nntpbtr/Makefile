# New ports collection makefile for:    nntpbtr
# Version required:     1.7
# Date created:         1 July 1996
# Whom:                 dk
#
# $Id$
#

DISTNAME=       nntpbtr-1.7
CATEGORIES+=	news
MASTER_SITES=   ftp://ftp.kiae.su/unix/news/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	dk@farm.org

# "patch" complains otherwise
post-extract:
	rm -rf ${WRKSRC}/RCS

pre-build:
	cd ${FILESDIR} ; pax -rw -l -u dbz ${WRKDIR} || true
	cd ${WRKDIR}/dbz ; ${CC} ${CFLAGS} -c -I. dbz.c

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/nntpbtr.1
.endif

.include <bsd.port.mk>
