# Ports collection Makefile for: atmsupport
# Date created:		02 January 2004
# Whom:			harti
#
# $FreeBSD$
#

PORTNAME=	atmsupport
PORTVERSION=	1.7
PORTREVISION=
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	harti/atm

MAINTAINER=	harti@FreeBSD.org
COMMENT=	Tools for testing the ATM subsystem

LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84

USE_GMAKE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS+=	--with-tcldir=${LOCALBASE}
INSTALLS_SHLIB=	yes

MAN1=	unidecode.1 uniencode.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501114
IGNORE=		"ngATM not implemented on FreeBSD 4.x, 5.1 and earlier"
.endif

.include <bsd.port.post.mk>
