PORTNAME=	hbiff
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/misc/  \
		LOCAL/obrien

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Replacement for xbiff that handles popup window with mail headers

USES=		localbase xorg
USE_XORG=	x11

CFLAGS+=	-L${LOCALBASE}/lib
LDFLAGS+=	-lX11

PLIST_FILES=	bin/hbiff man/man1/hbiff.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/hbiff.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
