# New ports collection makefile for:	cfengine
# Version required:     1.4.12
# Date created:		March 16, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=       cfengine-1.4.12
CATEGORIES=	sysutils
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	cfengine

MAINTAINER=	jseger@FreeBSD.org

.if defined(PACKAGE_BUILDING) && !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

GNU_CONFIGURE=yes
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include <bsd.port.mk>
