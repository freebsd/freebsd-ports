# New ports collection makefile for:	pwg
# Date created:				19 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	pwg
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.8ung.at/tuxsoft/pwg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small tool to generate secure, random passwords

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

pre-configure:
	${REINPLACE_CMD} -e 's|-pedantic ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
