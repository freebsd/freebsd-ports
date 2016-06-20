# Created by: trevor
# $FreeBSD$

PORTNAME=	rfstool
PORTVERSION=	0.14
CATEGORIES=	sysutils
MASTER_SITES=	NETBSD
DISTNAME=	rfstool-0.14-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read from a Reiser file system

PLIST_FILES=	bin/rfstool
USES=		dos2unix zip
DOS2UNIX_FILES=	reiserfs.h
WRKSRC=		${WRKDIR}/rfstool-0.14/RFSTOOL
MAKEFILE=	makefile.gcc3x

post-extract:
	@${REINPLACE_CMD} -e "s,g++,\$${CXX},g" ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rfstool ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
