PORTNAME=	pcf2bdf
PORTVERSION=	1.07
CATEGORIES=	x11-fonts

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert X font from PCF to BDF

LICENSE=	MIT

USES=		cpe

USE_GITHUB=	yes
GH_ACCOUNT=	ganaware

CPE_VENDOR=	pcf2bdf_project

MAKEFILE=	Makefile.gcc
MAKE_ENV=	MANPATH="${PREFIX}/share/man/man1" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_MAN}" \
		INSTALL_DIR="${MKDIR}"

PLIST_FILES=	bin/pcf2bdf \
		share/man/man1/pcf2bdf.1.gz

.include <bsd.port.mk>
