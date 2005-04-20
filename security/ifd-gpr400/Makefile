# New ports collection makefile for:	ifd-gpr400
# Date created:		23 August 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	ifd-gpr400
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	http://www.innovationsw.com/~jaiger/downloads/smartcard/

MAINTAINER=	bms@FreeBSD.org
COMMENT=	PC/SC Lite driver for Gemplus GPR400 PCMCIA Smart Card Readers

BUILD_DEPENDS=	${LOCALBASE}/include/ifdhandler.h:${PORTSDIR}/security/ifd-devkit
LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

MAKE_ENV+=	DESTDIR="${PREFIX}"

INSTALLS_SHLIB= yes

NOMAN=

.include <bsd.port.mk>
