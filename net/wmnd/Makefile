# New ports collection makefile for:	wmnd
# Date created:				29 October 2001
# Whom:					Paolo Pisati <flag@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	wmnd
PORTVERSION=	0.4.12
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yuv.info/pub/wmnd/releases/

MAINTAINER=	flag@gufi.org
COMMENT=	Improved network monitoring dock app (with tons of features)

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${EXAMPLESDIR} --with-drivers="freebsd_sysctl" \
		--program-transform-name=""

MAN1=		wmnd.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
