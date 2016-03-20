# Created by: alex@FreeBSD.org
# $FreeBSD$

PORTNAME=	mindterm-binary
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	LOCAL/alex
DISTNAME=	mindtermbin-v121
DISTFILES=	mindterm-ssh.html ${EXTRACT_ONLY}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full vt220 compatible Java SSH-1 client (not only for websites)

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes
NO_CDROM=	Do not sell for profit

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${DISTDIR}/mindterm-ssh.html ${WRKSRC}
	${MV} ${WRKSRC}/mindtermfull.jar ${WRKSRC}/mindterm.jar

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/java/mindterm
	${INSTALL_DATA} ${WRKSRC}/mindterm.jar ${STAGEDIR}${PREFIX}/share/java/mindterm/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in CHANGES FAQ FEATURES PLATFORMS TODO mindterm-ssh.html
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
