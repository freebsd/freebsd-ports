PORTNAME=	screenie
PORTVERSION=	20120406
CATEGORIES=	sysutils
MASTER_SITES=	SF/screenie

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and lightweight screen(1) wrapper
WWW=		https://sourceforge.net/projects/screenie/

LICENSE=	GPLv2

RUN_DEPENDS=	screen:sysutils/screen

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/screenie share/man/man1/screenie.1.gz

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
