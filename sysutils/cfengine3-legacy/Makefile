# New ports collection makefile for:	cfengine
# Version required:     1.4.12
# Date created:		March 16, 1998
# Whom:			jseger@FreeBSD.ORG
#
# $Id: Makefile,v 1.3 1998/12/10 02:18:15 jseger Exp $
#

DISTNAME=       cfengine-1.4.12
CATEGORIES=	sysutils
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	cfengine

MAINTAINER=	jseger@FreeBSD.ORG

.if defined(PACKAGE_BUILDING)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

GNU_CONFIGURE=yes
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include <bsd.port.mk>
