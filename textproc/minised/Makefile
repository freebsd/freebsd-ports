PORTNAME=	minised
PORTVERSION=	1.15
CATEGORIES=	textproc
MASTER_SITES=	http://dl.exactcode.de/oss/minised/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Smaller, cheaper, faster sed implementation

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} man/man1/minised.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-O1||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
