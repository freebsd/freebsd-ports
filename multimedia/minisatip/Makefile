PORTNAME=	minisatip
PORTVERSION=	2.0.27
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Multi-threaded SATIP server that supports DVB cards
WWW=		https://github.com/catalinii/minisatip

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libdvbcsa.so:multimedia/libdvbcsa

USES=		gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	catalinii

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
ALL_TARGET=	minisatip

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minisatip ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DATADIR})

.include <bsd.port.post.mk>
