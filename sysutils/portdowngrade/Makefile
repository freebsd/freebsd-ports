# New ports collection makefile for:    portdowngrade
# Date created:                         2003/02/13
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	portdowngrade
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	h.eichmann@gmx.de
COMMENT=Sets a port back to a previous version

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

POPT_INCLUDE=	`pkg_info -xL ^popt | ${GREP} popt.h | ${SED} -e 's?/popt.h??'`
POPT_LIB=	`pkg_info -xL ^popt | ${GREP} libpopt.a | ${SED} -e 's?/libpopt.a??'`
CONFIGURE_ENV=	CPPFLAGS="-I${POPT_INCLUDE}" \
		LIBS="-lpopt -L${POPT_LIB}"

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_BZIP2=	yes

MAN1=		portdowngrade.1
PLIST_FILES=	sbin/portdowngrade

.include <bsd.port.mk>
