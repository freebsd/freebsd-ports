# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	ari-yahoo
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A console Yahoo! messenger client

PLIST_FILES=	bin/ari-yahoo
USE_GMAKE=	yes
USE_GCC=	any
USE_AUTOTOOLS=	autoconf

NO_STAGE=	yes
pre-configure:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in
	@(cd ${WRKSRC}/libyahoo && ${SETENV} ${AUTOCONF_ENV} ${AUTOCONF} \
		${AUTOCONFARGS})


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ari-yahoo ${PREFIX}/bin

.include <bsd.port.mk>
