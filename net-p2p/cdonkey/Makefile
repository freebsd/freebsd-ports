# ex:ts=8
# Ports collection makefile for:	cDonkey
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cdonkey
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.sourcefiles.org/Internet/File_Sharing/Edonkey/
DISTNAME=	cDonkey-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open and free core client for the eDonkey protocol

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

PLIST_FILES=	bin/cDonkey
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-berkeley-db="${LOCALBASE}/include/db3:${LOCALBASE}/lib"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/cDonkey-${PORTVERSION}

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s|-ldb|-ldb3|g" ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|/etc/|${LOCALBASE}/etc/|" \
		${WRKSRC}/donkey.cpp ${WRKSRC}/donkey.h

.include <bsd.port.post.mk>
