# New ports collection makefile for:	slurp
# Version required:	1.10
# Date created:		30 Jun 1996
# Whom:			jraynard
#
# $Id$
#

DISTNAME=	slurp-1.10
CATEGORIES+=	news
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/news/slurp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jraynard@FreeBSD.ORG

#RUN_DEPENDS=	${PREFIX}/etc/innd:${PORTSDIR}/news/inn

NO_WRKSUBDIR=	yes

pre-build:
	@(cd ${WRKSRC}; cp conf.h conf.h.orig; \
	  sed -e 's!/usr/lib/news!${PREFIX}/news/lib!' -e 's!/var/spool!/var!' conf.h.orig > conf.h; \
	rm -f syslog.h)
	@cp ${FILESDIR}/dbz.* ${WRKSRC}

do-install:
	mkdir -p ${PREFIX}/news/bin ${PREFIX}/news/lib
	install -c -o news -g news -m 0555 -s ${WRKSRC}/slurp ${PREFIX}/news/bin/
	install -c -o man -g man -m 0444 ${WRKSRC}/slurp.1 ${PREFIX}/man/man1
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/slurp.1
.endif
	install -c -o news -g news -m 0644 ${WRKSRC}/slurp.sys ${PREFIX}/news/lib/	

.include <bsd.port.mk>
