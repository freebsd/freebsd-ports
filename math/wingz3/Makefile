# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	wingzpro
PORTVERSION=	311
PORTREVISION=	2
CATEGORIES=	math linux
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=apps/financial/spreadsheet
EXTRACT_ONLY=

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A Commercial Spreadsheet

NO_PACKAGE=	"nothing to build. commercial software"

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs

NO_BUILD=	yes

# XXX: this is missing "${BRANDELF} -t Linux <executables>"

NO_STAGE=	yes
do-install:
	${TAR} -xzp -C ${LOCALBASE} -f ${DISTDIR}/${DISTFILES}
	${SED} 's%_LOCALBASE_%${LOCALBASE}%' \
		< ${FILESDIR}/Wingz3 \
		> ${LOCALBASE}/bin/Wingz3
	${CHMOD} 755 ${LOCALBASE}/bin/Wingz3

.include <bsd.port.mk>
