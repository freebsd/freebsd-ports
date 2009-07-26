# Ports collection Makefile for: atmsupport
# Date created:		02 January 2004
# Whom:			harti
#
# $FreeBSD$
#

PORTNAME=	atmsupport
PORTVERSION=	1.8
PORTREVISION=
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	harti/atm

MAINTAINER=	harti@FreeBSD.org
COMMENT=	Tools for testing the ATM subsystem

LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tcldir=${LOCALBASE}
USE_LDCONFIG=	yes

MAN1=	unidecode.1 uniencode.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000 && ${ARCH} == "amd64"
BROKEN=		does not compile
.endif

.include <bsd.port.post.mk>
