# ex:ts=8
# Ports collection makefile for:	cDonkey
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cdonkey
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.sourcefiles.org/Internet/File_Sharing/Edonkey/
DISTNAME=	cDonkey-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open and free core client for the eDonkey protocol

PLIST_FILES=	bin/cDonkey
USE_BDB=	41
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-berkeley-db="${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/cDonkey-${PORTVERSION}

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s|-ldb|-l${BDB_LIB_NAME}|g" ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|/etc/|${LOCALBASE}/etc/|" \
		${WRKSRC}/donkey.cpp ${WRKSRC}/donkey.h

.include <bsd.port.post.mk>
