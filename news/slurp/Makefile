# New ports collection makefile for:	slurp
# Version required:	1.10
# Date created:		30 Jun 1996
# Whom:			jraynard
#
# $Id: Makefile,v 1.1.1.1 1996/07/27 21:54:11 asami Exp $
#

DISTNAME=	slurp-1.10
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/news/slurp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jraynard@FreeBSD.ORG

#RUN_DEPENDS=	${PREFIX}/etc/innd:${PORTSDIR}/news/inn

NO_WRKSUBDIR=	yes
MAN1=		slurp.1

pre-build:
	@(cd ${WRKSRC}; cp conf.h conf.h.orig; \
	  sed -e 's!/usr/lib/news!${PREFIX}/news/lib!' -e 's!/var/spool!/var!' conf.h.orig > conf.h; \
	rm -f syslog.h)
	@cp ${FILESDIR}/dbz.* ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/news/bin ${PREFIX}/news/lib
	install -c -o news -g news -m 0555 -s ${WRKSRC}/slurp ${PREFIX}/news/bin/
	${INSTALL_MAN} ${WRKSRC}/slurp.1 ${PREFIX}/man/man1
	install -c -o news -g news -m 0644 ${WRKSRC}/slurp.sys ${PREFIX}/news/lib/	

.include <bsd.port.mk>
