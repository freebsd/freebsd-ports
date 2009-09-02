# New ports collection makefile for:   snoopy
# Date created:                3 February 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	snoopy
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}logger/${PORTNAME}logger/${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	An execve() wrapper and logger

PLIST_FILES=	lib/snoopy.so bin/detect
PORTDOCS=	README

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snoopy.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/detect ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
