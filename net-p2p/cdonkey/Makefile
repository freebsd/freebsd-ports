# Created by: ijliao
# $FreeBSD$

PORTNAME=	cdonkey
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.sourcefiles.org/Internet/File_Sharing/Edonkey/
DISTNAME=	cDonkey-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open and free core client for the eDonkey protocol

BROKEN=		no suitable distfile
FORBIDDEN=	distfile got re-rolled
DEPRECATED=	depends on deprecated db41 version
EXPIRATION_DATE=2014-09-30

WRKSRC=		${WRKDIR}/cDonkey-${PORTVERSION}

USE_BDB=	41
USES=		gmake libtool tar:bzip2
USE_AUTOTOOLS=	libtoolize
CONFIGURE_ARGS=	--with-berkeley-db="${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}"

PLIST_FILES=	bin/cDonkey

post-patch:
	@${REINPLACE_CMD} -e \
		's|-ldb|-l${BDB_LIB_NAME}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-fno-for-scope||' ${WRKSRC}/Makefile.in
.for i in donkey.cpp donkey.h
	@${REINPLACE_CMD} -e \
		's|/etc/|${LOCALBASE}/etc/|' ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
