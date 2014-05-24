# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	netstiff
PORTVERSION=	20080331
CATEGORIES=	www
MASTER_SITES=	http://pkqs.net/~sbeyer/tools/netstiff/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful web page update checker

LICENSE=	GPLv3

NO_BUILD=	yes
USE_RUBY=	yes
USES=		shebangfix
SHEBANG_FILES=	${WRKSRC}/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
PORTDOCS=	ChangeLog LICENSE THANKSTO
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
