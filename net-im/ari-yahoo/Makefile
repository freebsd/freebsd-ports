# New ports collection makefile for:   ari-yahoo
# Date created:        15 November 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ari-yahoo
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A console Yahoo! messenger client

USE_GMAKE=	yes
USE_AUTOCONF_VER=	253
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

pre-configure:
	@(cd ${WRKSRC}/libyahoo && ${SETENV} ${AUTOCONF_ENV} ${AUTOCONF} \
		${AUTOCONFARGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ari-yahoo ${PREFIX}/bin

.include <bsd.port.mk>
