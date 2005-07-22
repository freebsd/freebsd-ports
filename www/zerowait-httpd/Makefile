# New ports collection makefile for:	0W-httpd
# Date created:				17 March 2005
# Whom:					Vsevolod Stakhov
#
# $FreeBSD$
#

PORTNAME=	zerowait-httpd
PORTVERSION=	0.7m
CATEGORIES=	www
MASTER_SITES=	http://www.0w.ru/httpd/
DISTNAME=	0W-httpd-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Lightweight and fast http server

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	yes

MAKE_ARGS=	CFLAGS="${CFLAGS}" CPPFLAGS=-I..
WWW_USER?=	${WWWOWN}
WWW_GROUP?=	${WWWGRP}

pre-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' -e 's,%%RC_SUBR%%,${RC_SUBR},' \
			${FILESDIR}/0W-httpd.sh > ${WRKDIR}/0W-httpd.sh
	@${SH} -c 'cd ${WRKSRC} && ./configure --prefix=${PREFIX} --owner=${WWW_USER} --group=${WWW_GROUP}'

post-install:
	@${INSTALL_SCRIPT} -m 755 ${WRKDIR}/0W-httpd.sh ${PREFIX}/etc/rc.d/0W-httpd.sh

.include <bsd.port.mk>
