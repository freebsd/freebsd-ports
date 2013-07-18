# Created by: ijliao
# $FreeBSD$

PORTNAME=	xbiso
PORTVERSION=	0.6.1
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XBox xdvdfs iso extraction utility

LIB_DEPENDS=	ftp.3:${PORTSDIR}/ftp/ftplib

BROKEN=		Does not compile with ftplib>=4.0

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/xbiso

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CPPFLAGS)|@CPPFLAGS@|g ; \
		 s|= @LIBS@|= @LDFLAGS@ @LIBS@|g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbiso ${PREFIX}/bin

.include <bsd.port.mk>
