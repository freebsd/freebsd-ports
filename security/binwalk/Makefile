# New ports collection makefile for: binwalk
# Date created: 6 February 2012
# Whom: Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	binwalk
PORTVERSION=	0.4.2
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Search binary images for embedded files and executable code

LICENSE=	MIT

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

PLIST_FILES=	bin/binwalk \
		etc/binwalk/magic.binarch \
		etc/binwalk/magic.bincast \
		etc/binwalk/magic.binwalk \
		etc/binwalk/magic.o
PLIST_DIRS=	etc/binwalk

PORTDOCS=	README

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/docs/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
