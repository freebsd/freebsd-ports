# New ports collection makefile for:    wn
# Version required:     1.16
# Date created:         4 May 1995
# Whom:                 adam
#
# $Id: Makefile,v 1.14 1996/08/29 04:17:11 adam Exp $
#

DISTNAME=       wn-1.16.1
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.acns.nwu.edu/pub/wn/

IS_INTERACTIVE=
NO_PACKAGE=	# hostname compiled in

pre-patch:
	@cp ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile
	@cp ${WRKSRC}/config.h.dist ${WRKSRC}/config.h

post-install:
	@mkdir -p ${PREFIX}/wn/wnlogs ${PREFIX}/wn/bin
	@cp -PR ${WRKSRC}/docs ${PREFIX}/wn
	@install -c -o bin -g bin  ${WRKSRC}/bin/wn ${PREFIX}/libexec
	@install -c -o bin -g bin  ${WRKSRC}/bin/swn ${PREFIX}/sbin
	@install -c -o bin -g bin  ${WRKSRC}/bin/wndex ${PREFIX}/bin
	@install -c -o bin -g bin  ${WRKSRC}/bin/mkpasswd ${PREFIX}/wn/bin
	@install -c -o bin -g bin  ${WRKSRC}/bin/authwn ${PREFIX}/wn/bin
	@if [ -s ${PREFIX}/etc/wn_mime.types ]; then \
	    cmp -s ${PREFIX}/etc/wn_mime.types ${WRKSRC}/lib/mime.types || \
		echo Warning: new ${PREFIX}/etc/wn_mime.types not installed; \
	else \
	    install -c -o bin -g bin -m 644 ${WRKSRC}/lib/mime.types \
	                                     ${PREFIX}/etc/wn_mime.types; \
	fi
	@if [ -s ${PREFIX}/wn/index ]; then \
	    cmp -s ${PREFIX}/wn/index ${WRKDIR}/index || \
		echo Warning: new ${PREFIX}/wn/index not installed; \
	else \
	    install -c -o bin -g bin -m 644 ${WRKDIR}/index ${PREFIX}/wn; \
	fi
	@cd ${PREFIX}/wn; ../bin/wndex -r

.include <bsd.port.mk>
