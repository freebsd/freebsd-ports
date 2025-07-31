PORTNAME=	libarms
PORTVERSION=	6.33
CATEGORIES=	net devel
MASTER_SITES=	https://dev.smf.jp/dl/

MAINTAINER=	shigeru@iij.ad.jp
COMMENT=	SMFv2/ARMS client library for C
WWW=		https://dev.smf.jp/libarms/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake libtool localbase ssl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
# NetBSD's SIMPLEQ_* macros are called STAILQ_* on FreeBSD
	@${REINPLACE_CMD} -e 's,SIMPLEQ_,STAILQ_,' \
		${WRKSRC}/libarms/cache.c \
		${WRKSRC}/module/module_db_mi.c \
		${WRKSRC}/protocol/proto_push_read_status.c \
		${WRKSRC}/protocol/proto_push_read_storage.c

.include <bsd.port.mk>
