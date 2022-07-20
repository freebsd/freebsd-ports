PORTNAME=	ripole
PORTVERSION=	0.2.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.pldaniels.com/ripole/

MAINTAINER=	fcash@sd73.bc.ca
COMMENT=	Small program designed to pull attachments out of OLE2 documents

ALL_TARGET=	default

PLIST_FILES=	bin/ripole

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
