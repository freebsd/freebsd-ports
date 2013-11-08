# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	rarcrack
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/%5BUnnamed%20release%5D

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Rarcrack guesses the passwords of encrypted RAR, ZIP, and 7Z archives

DEPRECATED=	Not active since several years
EXPIRATION_DATE=	2013-12-08

RUN_DEPENDS=	p7zip:${PORTSDIR}/archivers/p7zip \
		unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip

USE_BZIP2=	yes
PLIST_FILES=	bin/rarcrack
PORTDOCS=	README
USE_GNOME=	libxml2
USE_CSTD=	gnu89
MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rarcrack ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
