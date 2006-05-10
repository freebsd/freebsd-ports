# ports collection makefile for:	skyutils
# Date created:				21 February 2004
# Whom: 				Machiel Mastenbroek <machiel_mastenbroek@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	skyutils
PORTVERSION=	2.8
CATEGORIES=	misc
MASTER_SITES=	http://zekiller.skytech.org/fichiers/

MAINTAINER=	machiel_mastenbroek@hotmail.com
COMMENT=	A library required by smssend (same author)

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_AUTOTOOLS=	autoconf:259 libtool:15
INSTALLS_SHLIB=	yes

pre-configure:
	@${REINPLACE_CMD} -e's/[[:cntrl:]]*$$//' ${WRKSRC}/src/skyutils.h

.include <bsd.port.mk>
