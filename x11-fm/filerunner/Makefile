PORTNAME=	filerunner
PORTVERSION=	23.03.07.16
CATEGORIES=	x11-fm tk
MASTER_SITES=	SF/${PORTNAME}/release-${PORTVERSION}
DISTNAME=	fr-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk-based filemanager with FTP capabilities
WWW=		https://sourceforge.net/projects/filerunner/

LICENSE=	GPLv2

USES=		tk:run
USE_LDCONFIG=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/env wish|${WISH}|' ${WRKSRC}/fr

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
.for file in fr frftp
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/${file}
.endfor
	@${LN} -sf ${DATADIR}/fr ${STAGEDIR}${PREFIX}/bin/fr

.include <bsd.port.mk>
