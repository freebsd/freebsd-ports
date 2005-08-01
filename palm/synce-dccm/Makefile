# New ports collection makefile for:   synce-dccm
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-dccm
PORTVERSION=	0.9.1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	Listener daemon for connections from WinCE devices

LIB_DEPENDS+=	synce.0:${PORTSDIR}/palm/synce-libsynce

MAN1=		dccm.1 synce-sound.1

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-libiconv=${LOCALBASE}
CONFIGURE_ARGS+=	--with-libsynce=${LOCALBASE}
USE_ICONV=	yes

post-install:
	@${ECHO_CMD} "*******************************************************************************"
	@${ECHO_CMD} "*** Edit ${PREFIX}/bin/synce-sound and substitute 'playwave' "
	@${ECHO_CMD} "*** for your wavefile player of choice."
	@${ECHO_CMD} "*******************************************************************************"

.include <bsd.port.mk>
