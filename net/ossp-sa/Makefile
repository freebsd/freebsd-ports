# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ossp-sa
# Date created:		2003-01-31
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	sa
PORTVERSION=	1.2.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An abstraction library for the Unix socket API

LIB_DEPENDS=	ex.10:${PORTSDIR}/devel/ossp-ex

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
MAN3+=		sa.3

.include <bsd.port.mk>
