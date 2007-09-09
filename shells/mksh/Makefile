# Ports collection makefile for:	mksh
# Date created:				2006-06-24
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		mksh
DISTVERSION=		R31
CATEGORIES=		shells
MASTER_SITES=		http://www.mirbsd.org/MirOS/dist/mir/mksh/ \
			http://pub.allbsd.org/MirOS/dist/mir/mksh/
DISTFILES=		${PORTNAME}-${DISTVERSION}.cpio.gz

MAINTAINER=		miwi@FreeBSD.org
COMMENT=		A MirBSD enhanced shell based on pdksh

WRKSRC=			${WRKDIR}/${PORTNAME}

MAN1=			mksh.1
PLIST_FILES=		bin/mksh share/examples/mksh/dot.mkshrc
PLIST_DIRS=		share/examples/mksh

PKGINSTALL=		pkg-install
PKGDEINSTALL=		pkg-deinstall

.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
		${GZCAT} ${DISTDIR}/${DISTFILES} | ${CPIO} -id

do-build:
	cd ${WRKSRC} && CFLAGS="${CFLAGS}" CC="${CC}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" SHELL=${SH} ${SH} ${WRKSRC}/Build.sh -q -r

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksh ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dot.mkshrc ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${MANPREFIX}/man/man1

pre-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
