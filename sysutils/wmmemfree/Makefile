PORTNAME=	wmmemfree
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	SUNSITE/X11/xutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Memory and swap monitoring dockapp

LICENSE=	GPLv2+

USES=		localbase tar:bzip2 xorg
USE_XORG=	x11 xext xpm

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${CP} ${FILESDIR}/mem_freebsd.* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
