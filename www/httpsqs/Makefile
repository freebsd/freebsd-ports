# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	httpsqs
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	lichray@gmail.com
COMMENT=	Simple Queue Service based on HTTP GET/POST protocol

LICENSE=	BSD3CLAUSE

LIB_DEPENDS+=	libtokyocabinet.so:databases/tokyocabinet \
		libevent.so:devel/libevent2

USES=		pkgconfig

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${CP} ${PATCHDIR}/Makefile ${WRKSRC}
	@${REINPLACE_CMD} -e 's|{ 0 }|"${PREFIX}/bin/${PORTNAME}"|' \
		${WRKSRC}/httpsqs.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
