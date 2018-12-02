# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	pcf2bdf
PORTVERSION=	1.05
CATEGORIES=	x11-fonts

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Convert X font from PCF to BDF

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ganaware

MAKEFILE=	Makefile.gcc
MAKE_ENV=	MANPATH="${MANPREFIX}/man/man1" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_MAN}" \
		INSTALL_DIR="${MKDIR}"

PLIST_FILES=	bin/pcf2bdf man/man1/pcf2bdf.1.gz

.include <bsd.port.mk>
