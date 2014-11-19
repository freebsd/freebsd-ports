# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkg_cleanup
PORTVERSION=	2.1
CATEGORIES=	ports-mgmt
DISTFILES=

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Interactive program for deinstalling 'leaf' packages

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/pkg_cleanup \
		man/man1/pkg_cleanup.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000 && ${OSVERSION} < 900038
IGNORE=		requires r223289 or higher to compile
.endif
.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9: undefined reference to 'sqrt'
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} -R ${FILESDIR}/* ${WRKSRC}

do-build:
	make -C ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_cleanup ${STAGEDIR}${PREFIX}/sbin/pkg_cleanup
	${INSTALL_MAN} ${WRKSRC}/pkg_cleanup.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
