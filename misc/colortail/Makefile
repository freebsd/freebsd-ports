PORTNAME=	colortail
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/joakim666/colortail/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	tail(1) replacement with color support

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnuregex.so.6:devel/libgnuregex

USES=		localbase:ldflags

GNU_CONFIGURE=	yes
LIBS+=		-lgnuregex

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colortail ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example-conf/conf* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
