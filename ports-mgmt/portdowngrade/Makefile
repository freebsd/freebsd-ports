# New ports collection makefile for:    portdowngrade
# Date created:                         2003/02/13
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	portdowngrade
PORTVERSION=	0.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	Sets a port back to a previous version

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

POPT_INCLUDE=	`pkg_info -xL ^popt | ${GREP} popt.h | ${SED} -e 's?/popt.h??'`
POPT_LIB=	`pkg_info -xL ^popt | ${GREP} libpopt.a | ${SED} -e 's?/libpopt.a??'`
CONFIGURE_ENV=	CPPFLAGS="-I${POPT_INCLUDE}" \
		LIBS="-lpopt -L${POPT_LIB}"
.if defined(DEFAULT_CVS_SERVER)
CONFIGURE_ARGS+=	--enable-default-server=${DEFAULT_CVS_SERVER}
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

USE_BZIP2=	yes

MAN1=		portdowngrade.1
PLIST_FILES=	sbin/portdowngrade

pre-everything::
.if !defined(DEFAULT_CVS_SERVER)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define DEFAULT_CVS_SERVER"
	@${ECHO_MSG} "(e.g. make DEFAULT_CVS_SERVER=\":pserver:anoncvs@anoncvs. ... .FreeBSD.org:/home/ncvs\" install)"
	@${ECHO_MSG} "if you want to use a special CVS server as default."
	@${ECHO_MSG} ""
	@sleep 3
.endif

.include <bsd.port.mk>
