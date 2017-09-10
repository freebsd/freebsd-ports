# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dmidecode
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for dumping DMI (SMBIOS) contents in human-readable format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

OPTIONS_DEFINE=	DOCS

MAKE_ENV=	DOCSDIR="${DOCSDIR}"
USES=		tar:xz

PLIST_FILES=	etc/periodic/daily/dmidecode \
		man/man8/biosdecode.8.gz \
		man/man8/dmidecode.8.gz \
		man/man8/ownership.8.gz \
		man/man8/vpddecode.8.gz \
		sbin/biosdecode \
		sbin/dmidecode \
		sbin/ownership \
		sbin/vpddecode
PORTDOCS=	AUTHORS CHANGELOG README
SUB_FILES=	dmidecode

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily/
	${INSTALL_SCRIPT} ${WRKDIR}/dmidecode ${STAGEDIR}${PREFIX}/etc/periodic/daily/

.include <bsd.port.mk>
