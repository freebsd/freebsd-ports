# $FreeBSD$

PORTNAME=	backupuser
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.olivermahmoudi.com/files/

MAINTAINER=	fbsd@olivermahmoudi.com
COMMENT=	User Backup Utility

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/backupuser \
		bin/bu_check_files \
		man/man1/backupuser.1.gz \
		man/man1/bu_check_files.1.gz
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME} bu_check_files \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 bu_check_files.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
