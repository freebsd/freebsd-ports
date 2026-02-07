PORTNAME=	pkg_cleanup
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive program for deinstalling 'leaf' packages

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/pkg_cleanup \
		share/man/man1/pkg_cleanup.1.gz

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -a ${FILESDIR}/ ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_cleanup ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pkg_cleanup.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
