# $FreeBSD$

PORTNAME=	backupuser
DISTVERSION=	1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.olivermahmoudi.com/files/

MAINTAINER=	fbsd@olivermahmoudi.com
COMMENT=	User Backup Utility

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/backupuser \
		bin/bu_check_files \
		man/man1/backupuser.1.gz \
		man/man1/bu_check_files.1.gz

post-patch:
	@${REINPLACE_CMD} '74,93d;101,103d' ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} 's|dpkg -l|pkg info|' ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|/bin/sh|${LOCALBASE}/bin/bash|' \
		-e 's|sha256sum|sha256|g' \
		${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|/bin/sh|${LOCALBASE}/bin/bash|' \
		-e 's|sha256sum|sha256|g' \
		${WRKSRC}/bu_check_files

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bu_check_files ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bu_check_files.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
