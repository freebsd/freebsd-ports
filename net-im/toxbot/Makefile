PORTNAME=	toxbot
DISTVERSION=	g20180325
PORTREVISION=	1
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Groupchat control bot for Tox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtoxcore.so:net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	JFreegman
GH_PROJECT=	ToxBot
GH_TAGNAME=	1e4af05

USES=		gmake pkgconfig

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
