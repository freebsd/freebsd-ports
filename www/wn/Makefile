# New ports collection makefile for:    wn
# Date created:         4 May 1995
# Whom:                 adam
#
# $FreeBSD$
#

PORTNAME=	wn
PORTVERSION=	1.18.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}	# ftp://ftp.acns.nwu.edu/pub/wn/
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=	adam@veda.is

IS_INTERACTIVE=
NO_PACKAGE=	"Hostname compiled in"

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile
	@${CP} ${WRKSRC}/config.h.dist ${WRKSRC}/config.h

post-install:
	@${MKDIR} ${PREFIX}/wn/wnlogs ${PREFIX}/wn/bin
	@${CP} -PR ${WRKSRC}/docs ${PREFIX}/wn
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/wn ${PREFIX}/libexec
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/swn ${PREFIX}/sbin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/wndex ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/mkwnpasswd ${PREFIX}/wn/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/authwn ${PREFIX}/wn/bin
	@if [ -s ${PREFIX}/etc/wn_mime.types ]; then \
	    cmp -s ${PREFIX}/etc/wn_mime.types ${WRKSRC}/lib/mime.types || { \
		${ECHO_MSG} Warning: new mime.types installed as ${PREFIX}/etc/wn_mime.types-dist; \
		${INSTALL_DATA} ${WRKSRC}/lib/mime.types \
					${PREFIX}/etc/wn_mime.types-dist; } \
	else \
	    ${INSTALL_DATA} ${WRKSRC}/lib/mime.types \
			${PREFIX}/etc/wn_mime.types; \
	fi
	@if [ -s ${PREFIX}/wn/index ]; then \
	    cmp -s ${PREFIX}/wn/index ${WRKDIR}/index || { \
		${ECHO_MSG} Warning: new index installed as ${PREFIX}/wn/index-dist; \
		${INSTALL_DATA} ${WRKDIR}/index ${PREFIX}/wn/index-dist; } \
	else \
	    ${INSTALL_DATA} ${WRKDIR}/index ${PREFIX}/wn; \
	fi
	@cd ${PREFIX}/wn; ../bin/wndex -r

.include <bsd.port.mk>
