# New ports collection makefile for:	virtualpaper
# Date created:		13 June 1996
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	virtualpaper
PORTVERSION=	1.4
CATEGORIES=	print
MASTER_SITES=	http://www.research.digital.com:80/SRC/virtualpaper/cgi-bin/nph-download.tcl/sources.tar.Z?object=Virtual+Paper/
DISTFILES=	sources.tar.Z

MAINTAINER=	jdp@FreeBSD.org

BUILD_DEPENDS=	m3build-6:${PORTSDIR}/lang/modula-3
LIB_DEPENDS=	m3.6:${PORTSDIR}/lang/modula-3-lib

DIST_SUBDIR=	virtualpaper-1.4
MAN1=		LecternClient.1 Lectern.1 BuildLectern.1 EditLectern.1

do-build:
	@cd ${WRKSRC}/lecternclient; m3build
	@cd ${WRKSRC}/lecterndoc; m3build
	@cd ${WRKSRC}/lectern; m3build
	@cd ${WRKSRC}/ocr; m3build
	@cd ${WRKSRC}/buildlectern; m3build
	@cd ${WRKSRC}/editlectern; m3build

do-install:
	@${ECHO_MSG} "Installing files"
	@cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} \
		lecternclient/FreeBSD2/LecternClient \
		lectern/FreeBSD2/Lectern \
		buildlectern/FreeBSD2/BuildLectern \
		editlectern/FreeBSD2/EditLectern \
		${PREFIX}/bin; \
	    ${INSTALL_MAN} \
		lecternclient/FreeBSD2/LecternClient.1 \
		lectern/FreeBSD2/Lectern.1 \
		buildlectern/FreeBSD2/BuildLectern.1 \
		editlectern/FreeBSD2/EditLectern.1 \
		${PREFIX}/man/man1; \
	    ${INSTALL_MAN} \
		lecternclient/FreeBSD2/LecternClient.1.html \
		lectern/FreeBSD2/Lectern.1.html \
		buildlectern/FreeBSD2/BuildLectern.1.html \
		editlectern/FreeBSD2/EditLectern.1.html \
		${PREFIX}/lib/m3/www; \
	    if [ ! -d ${PREFIX}/share/virtualpaper ]; then \
		${MKDIR} ${PREFIX}/share/virtualpaper; \
		${CHMOD} 755 ${PREFIX}/share/virtualpaper; \
	    fi; \
	    ${INSTALL_DATA} COPYRIGHT ${PREFIX}/share/virtualpaper
	@${ECHO_MSG} "Stripping programs"
	@cd ${PREFIX}/bin; \
	    strip LecternClient Lectern BuildLectern EditLectern

.include <bsd.port.mk>
