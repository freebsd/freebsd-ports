# New ports collection makefile for:	dmidecode
# Date created:				19 November 2003
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dmidecode
PORTVERSION=	2.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		ftp://ftp.nuug.no/pub/anders/distfiles/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A tool for dumping DMI (SMBIOS) contents in human-readable format

ONLY_FOR_ARCHS=	i386 amd64 ia64

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PORTDOCS=	AUTHORS CHANGELOG README

MAN8=		biosdecode.8 dmidecode.8 ownership.8 vpddecode.8

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
