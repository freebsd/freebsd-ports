# New ports collection makefile for:    wn
# Version required:     1.18
# Date created:         4 May 1995
# Whom:                 adam
#
# $Id: Makefile,v 1.25 1998/01/21 21:51:41 adam Exp $
#

DISTNAME=       wn-1.18.6
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.acns.nwu.edu/pub/wn/

MAINTAINER=	adam@veda.is

IS_INTERACTIVE=
NO_PACKAGE=	"Hostname compiled in"

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile
	@${CP} ${WRKSRC}/config.h.dist ${WRKSRC}/config.h

post-install:
	@mkdir -p ${PREFIX}/wn/wnlogs ${PREFIX}/wn/bin
	@${CP} -PR ${WRKSRC}/docs ${PREFIX}/wn
	@install -c -o bin -g bin  ${WRKSRC}/bin/wn ${PREFIX}/libexec
	@install -c -o bin -g bin  ${WRKSRC}/bin/swn ${PREFIX}/sbin
	@install -c -o bin -g bin  ${WRKSRC}/bin/wndex ${PREFIX}/bin
	@install -c -o bin -g bin  ${WRKSRC}/bin/mkwnpasswd ${PREFIX}/wn/bin
	@install -c -o bin -g bin  ${WRKSRC}/bin/authwn ${PREFIX}/wn/bin
	@if [ -s ${PREFIX}/etc/wn_mime.types ]; then \
	    cmp -s ${PREFIX}/etc/wn_mime.types ${WRKSRC}/lib/mime.types || { \
		echo Warning: new mime.types installed as ${PREFIX}/etc/wn_mime.types-dist; \
		install -c -o bin -g bin -m 644 ${WRKSRC}/lib/mime.types \
					${PREFIX}/etc/wn_mime.types-dist; } \
	else \
	    install -c -o bin -g bin -m 644 ${WRKSRC}/lib/mime.types \
	                                     ${PREFIX}/etc/wn_mime.types; \
	fi
	@if [ -s ${PREFIX}/wn/index ]; then \
	    cmp -s ${PREFIX}/wn/index ${WRKDIR}/index || { \
		echo Warning: new index installed as ${PREFIX}/wn/index-dist; \
		install -c -o bin -g bin -m 644 ${WRKDIR}/index ${PREFIX}/wn/index-dist; } \
	else \
	    install -c -o bin -g bin -m 644 ${WRKDIR}/index ${PREFIX}/wn; \
	fi
	@cd ${PREFIX}/wn; ../bin/wndex -r

.include <bsd.port.mk>
