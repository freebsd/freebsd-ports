# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	ari-yahoo
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console Yahoo! messenger client

DEPRECATED=	Broken for more than 1 year (http://www.icculus.org/ari-yahoo/)
EXPIRATION_DATE=	2014-04-18

USES=		gmake
PLIST_FILES=	bin/ari-yahoo
USE_GCC=	any
USE_AUTOTOOLS=	autoconf

pre-configure:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in
	@(cd ${WRKSRC}/libyahoo && ${SETENV} ${AUTOCONF_ENV} ${AUTOCONF} \
		${AUTOCONFARGS})


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ari-yahoo ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
