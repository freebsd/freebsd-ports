# New ports collection makefile for:    wn
# Version required:     1.06
# Date created:         4 May 1995
# Whom:                 adam
#
# $Id: Makefile,v 1.4 1995/12/01 11:40:46 adam Exp $
#

DISTNAME=       wn-1.12.2
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.acns.nwu.edu/pub/wn/

IS_INTERACTIVE=
NO_PACKAGE=	# hostname compiled in

pre-patch: ${PATCH_COOKIE}
	@cp ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile
	@cp ${WRKSRC}/config.h.dist ${WRKSRC}/config.h

post-install:
	@mkdir -p ${PREFIX}/wn
	@cp -PR ${WRKSRC}/docs ${PREFIX}/wn
	@install -c -o bin -g bin  ${WRKSRC}/bin/wn ${PREFIX}/libexec
	@install -c -o bin -g bin  ${WRKSRC}/bin/swn ${PREFIX}/sbin
	@install -c -o bin -g bin  ${WRKSRC}/bin/wndex ${PREFIX}/bin
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
	@cd ${PREFIX}/wn; ../sbin/wndex -r

.include <bsd.port.mk>
