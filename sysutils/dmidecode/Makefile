# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dmidecode
PORTVERSION=	3.2
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for dumping DMI (SMBIOS) contents in human-readable format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		tar:xz

MAKE_ENV=	DOCSDIR="${DOCSDIR}"

SUB_FILES=	dmidecode

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_SCRIPT} ${WRKDIR}/dmidecode ${STAGEDIR}${PREFIX}/etc/periodic/daily/

.include <bsd.port.mk>
