# New ports collection makefile for:	mp4split
# Date created:				May 26, 2010
# Whom:					Marcus Hermansson <bmhermansson@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mp4split
PORTVERSION=	1.0.8
CATEGORIES=	multimedia
MASTER_SITES=	http://smoothstreaming.code-shop.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bmhermansson@gmail.com
COMMENT=	Converts MP4 files to Fragmented MP4 and creates manifest files

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/mp4split

RESTRICTED=	no-commercial-use

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
