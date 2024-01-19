PORTNAME=	minised
PORTVERSION=	1.16
CATEGORIES=	textproc
MASTER_SITES=	http://dl.exactcode.de/oss/minised/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Smaller, cheaper, faster sed implementation
WWW=		https://exactcode.com/opensource/minised/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} share/man/man1/minised.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-O1||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
