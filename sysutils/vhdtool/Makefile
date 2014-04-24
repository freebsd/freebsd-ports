# $FreeBSD$

PORTNAME=	vhdtool
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.glenbarber.us/ports/${CATEGORIES}/${PORTNAME}/ \
		LOCAL/gjb/${PORTNAME}

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	Convert raw disk images to VHD files

LICENSE=	GPLv2

USE_LDCONFIG=	yes
LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid
CFLAGS+=	-I${LOCALBASE}/include \
		-L${LOCALBASE}/lib \
		-I${LOCALBASE}/lib \
		-luuid

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for D in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${D} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
