# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	htpdate
PORTVERSION=	1.0.5
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.vervest.org/htp/archive/c/ \
		http://twekkel.home.xs4all.nl/htp/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Time synchronization over http utility

LICENSE=	GPLv2 # (or later)

USE_BZIP2=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MANCOMPRESSED=	yes
MAN8=		${PORTNAME}.8
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	Changelog README
USE_RC_SUBR=	${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8.gz ${MAN8PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
