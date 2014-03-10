# Created by: alex@FreeBSD.org
# $FreeBSD$

PORTNAME=	mindterm-binary
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alex
DISTNAME=	mindtermbin-v121
DISTFILES=	mindterm-ssh.html ${EXTRACT_ONLY}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full vt220 compatible Java SSH-1 client (not only for websites)

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_CDROM=	Do not sell for profit

NO_STAGE=	yes
post-extract:
	@${CP} ${DISTDIR}/mindterm-ssh.html ${WRKSRC}
	@${MV} ${WRKSRC}/mindtermfull.jar ${WRKSRC}/mindterm.jar

do-install:
	@${MKDIR} ${PREFIX}/share/java/mindterm
	@${INSTALL_DATA} ${WRKSRC}/mindterm.jar ${PREFIX}/share/java/mindterm/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for DOC in CHANGES FAQ FEATURES PLATFORMS TODO mindterm-ssh.html
	@${INSTALL_DATA} ${WRKSRC}/${DOC} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
