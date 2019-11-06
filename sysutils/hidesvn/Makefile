# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hidesvn
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://80386.nl/projects/${PORTNAME}/distfiles/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Utility that uses LD_PRELOAD to hide .svn directories

BROKEN=		unfetchable

USES=		shebangfix tar:xz
USE_LDCONFIG=	yes

PLIST_FILES=	bin/hidesvn lib/libhidesvn.so man/man1/hidesvn.1.gz
SHEBANG_FILES=	hidesvn.sh
MAKEFILE=	BSDmakefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
