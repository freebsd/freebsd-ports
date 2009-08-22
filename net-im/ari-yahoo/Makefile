# New ports collection makefile for:   ari-yahoo
# Date created:        15 November 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ari-yahoo
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A console Yahoo! messenger client

PLIST_FILES=	bin/ari-yahoo
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262

pre-configure:
	@(cd ${WRKSRC}/libyahoo && ${SETENV} ${AUTOCONF_ENV} ${AUTOCONF} \
		${AUTOCONFARGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ari-yahoo ${PREFIX}/bin

.include <bsd.port.mk>
