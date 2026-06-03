PORTNAME=	filerunner
DISTVERSION=	24.07.12.20
CATEGORIES=	x11-fm tk
MASTER_SITES=	SF/${PORTNAME}/release-${DISTVERSION}
DISTNAME=	fr-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk-based filemanager with FTP capabilities
WWW=		https://sourceforge.net/projects/filerunner/

LICENSE=	GPLv2

USES=		shebangfix tk:run
USE_LDCONFIG=	yes

SHEBANG_FILES=	fr frftp
tk_OLD_CMD=	"/usr/bin/env wish"

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
		'! ( -name fr -o -name frftp ) ')
	${INSTALL_SCRIPT} ${WRKSRC}/fr ${WRKSRC}/frftp ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/fr ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
