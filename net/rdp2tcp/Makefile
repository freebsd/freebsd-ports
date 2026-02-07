PORTNAME=	rdp2tcp
DISTVERSION=	0.1.0.20250804
CATEGORIES=	net comms

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
# https://github.com/V-E-O/rdp2tcp/pull/14
PATCHFILES+=	1e45654b6e23633a9c648d6b0c8bc5b133a0504b.patch:-p1

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Open tcp tunnel through remote desktop connection (client)
WWW=		https://github.com/V-E-O/rdp2tcp/

LICENSE=	GPLv3

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	V-E-O
GH_TAGNAME=	0a54991e669e8636b129a60e9ff5baa2fc91d1af
SHEBANG_FILES=	${TOOLS_PLIST_FILES:S|bin|tools|}

CFLAGS+=	-I${WRKSRC}/common

PLIST_FILES=	bin/rdp2tcp

OPTIONS_DEFINE=		TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes

TOOLS_DESC=		Install rdp2tcp.py and rdpupload
TOOLS_USES=		python:run
TOOLS_PLIST_FILES=	bin/rdp2tcp.py \
			bin/rdpupload

post-patch:
	@${REINPLACE_CMD} \
		-e 's|CC=.*||g' \
		-e 's|CFLAGS=.*||g' \
		-e 's|LDFLAGS=.*||g' \
		${WRKSRC}/client/Makefile \
		${WRKSRC}/common/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/client/rdp2tcp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/rdp2tcp.py \
			  ${WRKSRC}/tools/rdpupload ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
