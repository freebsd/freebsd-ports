PORTNAME=	pev
PORTVERSION=	0.80
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	PE analysis toolkit
WWW=		https://sourceforge.net/projects/pev/

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:devel/pcre

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake ssl
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

MAKE_ARGS=	MAKE=${MAKE_CMD}
CFLAGS+=	-I${OPENSSLINC} -I${LOCALBASE}/include
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
