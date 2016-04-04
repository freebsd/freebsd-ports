# Created by: Serge Gagnon <gagnon__s@videotron.ca>
# $FreeBSD$

PORTNAME=	disktool
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.auxio.org/pub/mirrors/step.polymtl.ca/pub/Xview/apps/disktool/
DISTNAME=	disktool-2.0c

MAINTAINER=	cy@FreeBSD.org
COMMENT=	XView sysadmin tool for monitoring diskfull situations

LIB_DEPENDS=	libxview.so:x11-toolkits/xview

WRKSRC=		${WRKDIR}/${DISTNAME}

ALL_TARGET=	disktool

PLIST_FILES=	bin/disktool man/man1/disktool.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/disktool ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/disktool.man \
		${STAGEDIR}${PREFIX}/man/man1/disktool.1

.include <bsd.port.mk>
