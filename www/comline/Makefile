# New ports collection makefile for:    comline
# Date created:         9 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	comline
PORTVERSION=	4.0D
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Library/Distribution/old/ \
		http://spinner.cisti.nrc.ca/mirror/dev.w3.org/libwww/old/ \
		http://ftp.rge.com/pub/infosystems/w3/old/comline/ \
		http://ftp.se.kde.org/pub/www/old/comline/ \
		http://www.rarf.riken.go.jp/archives/net/w3c/old/comline/
DISTFILES=	w3c-libwww-4.0D.tar.gz \
		w3c_4.0D_src.tar.gz

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/WWW

post-patch:
	@${REINPLACE_CMD} -e 's,strcasestr,strcasestr_,' \
		${WRKSRC}/Library/Implementation/HTString.*

do-build:
	cd ${WRKSRC}; ./BUILD comline

do-install:
	${INSTALL} -s -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/ComLine/freebsd/w3c ${PREFIX}/bin

.include <bsd.port.mk>
