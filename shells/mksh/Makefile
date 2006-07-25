# Ports collection makefile for:	mksh
# Date created:				2006-06-24
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		mksh
DISTVERSION=		R27e
CATEGORIES=		shells
MASTER_SITES=		http://www.mirbsd.org/MirOS/dist/mir/mksh/
DISTFILES=		${PORTNAME}-${DISTVERSION}.cpio.gz

MAINTAINER=		andreas@syndrom23.de
COMMENT=		A MirBSD enhanced shell based on pdksh

WRKSRC=			${WRKDIR}/${PORTNAME}

MAN1=			mksh.1
PLIST_FILES=		bin/mksh

OPTIONS=		STATIC_MKSH "Build static mksh" on

PKGINSTALL=		pkg-install
PKGDEINSTALL=		pkg-deinstall

.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
		${GZCAT} ${DISTDIR}/${DISTFILES} | ${CPIO} -id

do-build:
.if defined(WITH_STATIC_MKSH)
	cd ${WRKSRC} && CFLAGS="${CFLAGS}" CC="${CC}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" SHELL=${SH} ${SH} ${WRKSRC}/Build.sh -r
.else
	cd ${WRKSRC} && CFLAGS="${CFLAGS}" CC="${CC}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" SHELL=${SH} ${SH} ${WRKSRC}/Build.sh -d -r
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${MANPREFIX}/man/man1

pre-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
