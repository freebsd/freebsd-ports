PORTNAME=	bsdbktr_tvtune
PORTVERSION=	0.02
CATEGORIES=	multimedia
MASTER_SITES=	http://mina.naguib.ca/dist/

MAINTAINER=	mina.website@naguib.ca
COMMENT=	Console Brooktree (bktr) TV tuner
WWW=		https://web.archive.org/web/20050207003754/http://topfx.com/dist/bsdbktr_tvtune/

LICENSE=	NONE

DEPRECATED=	Requires defunct bktr
EXPIRATION_DATE=2023-12-31
.if !exists(/usr/include/dev/bktr/ioctl_bt848.h)
IGNORE=		needs bktr(4) which is no longer available on your FreeBSD version
.endif
ONLY_FOR_ARCHS=	i386

PLIST_FILES=	bin/bsdbktr_tvtune
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	bsdbktr_tvtune

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdbktr_tvtune ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
