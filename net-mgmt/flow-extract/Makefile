# New ports collection makefile for:	flow-extract
# Date created:				2003 Mar 14
# Whom:					Marcin Cieslak <saper@system.pl>
#
# $FreeBSD$
#

PORTNAME=	flow-extract
PORTVERSION=	2.61
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://answers.uchicago.edu/images/group68/19876/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cisco NetFlow awk-like extracting tool

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ftlib.h:${PORTSDIR}/net-mgmt/flow-tools

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

MAN1=		flow-extract.1
PLIST_FILES=	bin/flow-extract

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	${LOCALBASE}/lib/libft.a -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flow-extract ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flow-extract.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
