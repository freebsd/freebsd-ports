# New ports collection makefile for:   synce-librapi2
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-librapi2
PORTVERSION=	0.7
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	boris@brooknet.com.au
COMMENT=	Utilities/libraries to make RAPI calls on WinCE devices

LIB_DEPENDS+=	synce.0:${PORTSDIR}/palm/synce-libsynce

MAN1=		pcp.1 pls.1 pmkdir.1 pmv.1 prm.1 prmdir.1 prun.1 pstatus.1 synce-install-cab.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--program-transform-name=""
CONFIGURE_ARGS+=	--with-libsynce=${PREFIX}

INSTALLS_SHLIB=	yes
.include <bsd.port.mk>
