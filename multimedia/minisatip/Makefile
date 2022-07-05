PORTNAME=	minisatip
PORTVERSION=	1.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Multi-threaded SATIP server that supports DVB cards

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libdvbcsa.so:multimedia/libdvbcsa

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	catalinii

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
ALL_TARGET=	minisatip

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's|/usr/share/minisatip|${DATADIR}|' \
		${WRKSRC}/src/minisatip.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minisatip ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DATADIR})

.include <bsd.port.post.mk>
