# New ports collection makefile for:	giFT-OpenFT
# Date created:		2003-09-04
# Whom:			Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	giFT-OpenFT
PORTVERSION=	0.2.1.6
CATEGORIES=	net-p2p
MASTER_SITES=	SF/gift/${PORTNAME:L}/${PORTVERSION}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	shoesoft@gmx.net
COMMENT=	An OpenFT plugin for giFT

LIB_DEPENDS=	gift.0:${PORTSDIR}/net-p2p/gift \
		db3.3:${PORTSDIR}/databases/db3

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

DOC_FILES=	AUTHORS COPYING ChangeLog \
		INSTALL NEWS README TODO

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
