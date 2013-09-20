# Created by: ijliao
# $FreeBSD$

PORTNAME=	cdonkey
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.sourcefiles.org/Internet/File_Sharing/Edonkey/
DISTNAME=	cDonkey-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open and free core client for the eDonkey protocol

WRKSRC=		${WRKDIR}/cDonkey-${PORTVERSION}

USE_BZIP2=	yes
USE_BDB=	41
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-berkeley-db="${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}"

PLIST_FILES=	bin/cDonkey

NO_STAGE=	yes
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
