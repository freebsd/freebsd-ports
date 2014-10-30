# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	htpdate
PORTVERSION=	1.1.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.vervest.org/htp/archive/c/ \
		http://twekkel.home.xs4all.nl/htp/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Time synchronization over http utility

LICENSE=	GPLv2 # (or later)

USES=	tar:bzip2
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME} man/man8/${PORTNAME}.8.gz
PORTDOCS=	Changelog README
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
