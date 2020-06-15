# $FreeBSD$

PORTNAME=	mapdir
PORTVERSION=	1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.olivermahmoudi.com/files/

MAINTAINER=	fbsd@olivermahmoudi.com
COMMENT=	Tool to map directory trees

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mapdir \
		bin/mapdircmp \
		man/man1/mapdir.1.gz \
		man/man1/mapdircmp.1.gz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/sh|${LOCALBASE}/bin/bash|' \
		-e 's|md5sum|md5|g' \
		-e 's|sha256sum|sha256|g' \
 		-e 's|print $$1|print $$4|g' \
		${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|md5sum|md5|g' \
		-e 's|sha256sum|sha256|g' \
		${WRKSRC}/${PORTNAME}.1
	@${REINPLACE_CMD} -e 's|/bin/sh|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/${PORTNAME}cmp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}cmp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}cmp.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
