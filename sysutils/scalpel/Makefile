# New ports collection makefile for:	Scalpel
# Date created:				2011-12-22
# Whom:					Hakisho Nukama <nukama@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scalpel
PORTVERSION=	2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.digitalforensicssolutions.com/Scalpel/

MAINTAINER=	nukama@gmail.com
COMMENT=	A frugal, high performance file carver

LICENSE=	GPLv2

LIB_DEPENDS=	tre.5:${PORTSDIR}/textproc/libtre

GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

MAN1=		scalpel.1
PLIST_FILES+=	etc/scalpel.conf.sample bin/scalpel

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's/#ifdef __APPLE__/#if defined(__APPLE__) || defined(__FreeBSD__)/' \
		${WRKSRC}/src/scalpel.h

post-install:
	@${CP} -p ${WRKSRC}/scalpel.conf ${PREFIX}/etc/scalpel.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
