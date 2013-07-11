# $FreeBSD$

PORTNAME=	binwalk
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Search binary images for embedded files and executable code

LICENSE=	MIT

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

PLIST_FILES=	bin/binwalk \
		etc/binwalk/extract.conf \
		etc/binwalk/magic.binarch \
		etc/binwalk/magic.bincast \
		etc/binwalk/magic.binwalk
PLIST_DIRS=	etc/binwalk

PORTDOCS=	README

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/docs/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
