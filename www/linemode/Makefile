# New ports collection makefile for:	linemode
# Whom:			NIIMI Satoshi <sa2c@and.or.jp>
#
# $FreeBSD$
#

PORTNAME=	linemode
PORTVERSION=	4.0D
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/linemode/old/ \
		ftp://ftp.w3.org/pub/libwww/old/ \
		ftp://ftp-eu.w3.org/pub/linemode/old/ \
		ftp://ftp-eu.w3.org/pub/libwww/old/
DISTFILES=	w3c-libwww-${PORTVERSION}.tar.gz \
		www_${PORTVERSION}_src.tar.gz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/WWW

do-build:
	cd ${WRKSRC}; ./BUILD linemode

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LineMode/freebsd/www ${PREFIX}/bin/

.include <bsd.port.mk>
