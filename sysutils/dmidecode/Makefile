# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dmidecode
PORTVERSION=	2.12
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for dumping DMI (SMBIOS) contents in human-readable format

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386 amd64 ia64
MAKE_ENV=	DOCSDIR="${DOCSDIR}"
USES=		tar:bzip2

PLIST_FILES=	etc/periodic/daily/dmidecode \
		man/man8/dmidecode.8.gz \
		sbin/dmidecode
PORTDOCS=	AUTHORS CHANGELOG README
SUB_FILES=	dmidecode

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/dmidecode \
		${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_FILES+=	man/man8/biosdecode.8.gz \
		man/man8/ownership.8.gz \
		man/man8/vpddecode.8.gz \
		sbin/biosdecode \
		sbin/ownership \
		sbin/vpddecode
.endif

.include <bsd.port.post.mk>
