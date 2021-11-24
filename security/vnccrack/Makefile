# Created by: Pankov Pavel <pankov_p@mail.ru>

PORTNAME=	vnccrack
PORTVERSION=	1.0.0
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/vnccrack/
DISTNAME=	VNCcrack-${PORTVERSION}

MAINTAINER=	pankov_p@mail.ru
COMMENT=	Fast offline password cracker for VNC passwords

DEPRECATED=	Outdated and abandoned, last release in 2008. Upstream is at 2.1 while version in ports is 1.0.0
EXPIRATION_DATE=2022-03-31

USES=		ssl tar:tgz
GNU_CONFIGURE=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnccrack ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
