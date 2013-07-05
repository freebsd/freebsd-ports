# $FreeBSD$

PORTNAME=	jshon
PORTVERSION=	20121210
CATEGORIES=	textproc

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	json parser for the shell.

LICENSE=	MIT

LIB_DEPENDS=	jansson:${PORTSDIR}/devel/jansson

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	keenerd
GH_COMMIT=	b21bc98
GH_TAGNAME=	${GH_COMMIT}

CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/${PORTNAME}
MAN1=	${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's,-ljansson,-L${LOCALBASE}/lib -ljansson,g' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
