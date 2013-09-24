# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	htpdate
PORTVERSION=	1.0.7
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.vervest.org/htp/archive/c/ \
		http://twekkel.home.xs4all.nl/htp/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Time synchronization over http utility

LICENSE=	GPLv2 # (or later)

USE_BZIP2=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MANCOMPRESSED=	yes
PLIST_FILES=	bin/${PORTNAME} man/man8/${PORTNAME}.8.gz
PORTDOCS=	Changelog README
USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8.gz ${STAGEDIR}${MAN8PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
