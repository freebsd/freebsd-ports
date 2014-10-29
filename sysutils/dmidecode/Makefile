# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dmidecode
PORTVERSION=	2.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		ftp://ftp.nuug.no/pub/anders/distfiles/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for dumping DMI (SMBIOS) contents in human-readable format

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64 ia64

USES=	tar:bzip2
MAKE_ENV+=	DOCSDIR="${DOCSDIR}"

PLIST_FILES=	sbin/dmidecode \
		man/man8/dmidecode.8.gz

PORTDOCS=	AUTHORS CHANGELOG README

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_FILES+=	sbin/biosdecode sbin/ownership sbin/vpddecode \
		man/man8/biosdecode.8.gz man/man8/ownership.8.gz man/man8/vpddecode.8.gz
.endif

.include <bsd.port.post.mk>
