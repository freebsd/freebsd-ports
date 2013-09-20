# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dmidecode
PORTVERSION=	2.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		ftp://ftp.nuug.no/pub/anders/distfiles/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A tool for dumping DMI (SMBIOS) contents in human-readable format

ONLY_FOR_ARCHS=	i386 amd64 ia64

USE_BZIP2=	yes
MAKE_ENV+=	DOCSDIR="${DOCSDIR}"
LICENSE=	GPLv2

.if defined(NOPORTDOCS)
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/^install.*:/s,install-doc,,' ${WRKSRC}/Makefile

.else
PORTDOCS=	AUTHORS CHANGELOG README
.endif

MAN8=		dmidecode.8
PLIST_FILES=	sbin/dmidecode

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
MAN8+=		biosdecode.8 ownership.8 vpddecode.8
PLIST_FILES+=	sbin/biosdecode sbin/ownership sbin/vpddecode
.endif

.include <bsd.port.post.mk>
