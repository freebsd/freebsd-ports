# $FreeBSD$

PORTNAME=	rtmpdump
PORTVERSION=	2.4.20151223
CATEGORIES=	multimedia net
MASTER_SITES=	LOCAL/hrs
DISTNAME=	${PORTNAME}-2.4.fa8646da

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	RTMP streams download utility

LICENSE=	GPLv2

LIB_DEPENDS=	librtmp.so:multimedia/librtmp

USES=		pkgconfig tar:bz2
USE_OPENSSL=	yes
MAKE_ENV=	THREADLIB="-lpthread"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
