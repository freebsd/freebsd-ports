# New ports collection makefile for:   snoopy
# Date created:			24 October 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	rarcrack
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	jadawin@tuxaco.net
COMMENT=	 It's try to guess your encrypted compressed file's password

RUN_DEPENDS=	p7zip:${PORTSDIR}/archivers/p7zip \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip

USE_BZIP2=	yes
PLIST_FILES=	bin/rarcrack
PORTDOCS=	README
USE_GNOME=	libxml2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rarcrack ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
