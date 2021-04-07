PORTNAME=	toxins
DISTVERSION=	g20180217
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of small programs using toxcore

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libsodium.so:security/libsodium \
		libtoxcore.so:net-im/tox

USES=		gmake pkgconfig
USE_CSTD=	gnu99
USE_GITHUB=	yes
GH_ACCOUNT=	TokTok
GH_TAGNAME=	f76a7bd
ALL_TARGET=	build
GH_TUPLE=	hqwrong:minitox:45b9e3f:minitox/minitox/import

PROGS=		irc_syncbot tox_shell tox_sync echobot minitox

PLIST_FILES=	${PROGS:S/^/bin\//}

post-patch:
	@${RM} -r ${WRKSRC}/toxvpn # will be in a separate port
	@${REINPLACE_CMD} -e 's|-static -ltoxcore|`pkg-config --cflags --libs toxcore`|' ${WRKSRC}/*/Makefile

do-install:
.for f in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f}/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
