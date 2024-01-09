PORTNAME=	host-setup
PORTVERSION=	4.0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System configuration setup/management utility
WWW=		https://druidbsd.sourceforge.net/

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
