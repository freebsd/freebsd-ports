# ex:ts=8
# Ports collection makefile for:	cDonkey
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cdonkey
PORTVERSION=	0.8.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://suche.org/
DISTNAME=	cDonkey-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open and free core client for the eDonkey protocol

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

PLIST_FILES=	bin/cDonkey
USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-berkeley-db="${LOCALBASE}/include/db3:${LOCALBASE}/lib"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/cDonkey

post-patch:
	@${REINPLACE_CMD} -e "s|-ldb|-ldb3|g" ${WRKSRC}/configure

.include <bsd.port.mk>
