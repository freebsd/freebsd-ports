# $FreeBSD$

PORTNAME=	jshon
PORTVERSION=	20121210
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	json parser for the shell.

LICENSE=	MIT

LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	keenerd
GH_COMMIT=	b21bc98
GH_TAGNAME=	${GH_COMMIT}

CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,-ljansson,-L${LOCALBASE}/lib -ljansson,g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
