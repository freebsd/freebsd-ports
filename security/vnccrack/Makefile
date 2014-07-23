# Created by: Pankov Pavel <pankov_p@mail.ru>
# $FreeBSD$

PORTNAME=	vnccrack
PORTVERSION=	1.0.0
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/vnccrack/
DISTNAME=	VNCcrack-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pankov_p@mail.ru
COMMENT=	Fast offline password cracker for VNC passwords

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnccrack ${STAGEDIR}${PREFIX}/bin

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
