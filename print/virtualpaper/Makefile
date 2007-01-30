# New ports collection makefile for:	virtualpaper
# Date created:		13 June 1996
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	virtualpaper
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	print
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual Paper document storage and viewing software

BUILD_DEPENDS=	${L1}libm3formsvbt${L2}:${PORTSDIR}/lang/pm3-forms \
		nonexistent:${PORTSDIR}/lang/pm3-base:configure
RUN_DEPENDS=	${L1}libm3formsvbt${L2}:${PORTSDIR}/lang/pm3-forms

NOFETCHFILES=	yes
ONLY_FOR_ARCHS=	i386 alpha
DIST_SUBDIR=	pm3
INSTALL_TARGET=	all
MAN1=		BuildLectern.1 EditLectern.1 Lectern.1 LecternClient.1
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		INST_TARGET=${INST_TARGET} WORDSIZE=${WORDSIZE}
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../../lang/pm3-base/work/pm3-${PM3VERSION}

BUILDDIRS=	graphics/lecternpkg/lecternclient \
		graphics/lecternpkg/lecterndoc \
		graphics/lecternpkg/lectern \
		graphics/lecternpkg/ocr \
		graphics/lecternpkg/buildlectern \
		graphics/lecternpkg/editlectern
L1=		${PREFIX}/lib/m3/${TARGET}/
PM3VERSION=	1.1.15
PROGS=		bin/BuildLectern \
		bin/EditLectern \
		bin/Lectern \
		bin/LecternClient
SOVERSION=	7
# hack to work around bsd.port.mk problem
USE_BZIP2=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
L2=		.so.${SOVERSION}
TARGET=		FreeBSD4
INST_TARGET=	freebsd-4
WORDSIZE=	32
.elif ${ARCH} == "alpha"
CFLAGS+=	-mieee
L2=		.so.${SOVERSION}
TARGET=		FBSD_ALPHA
INST_TARGET=	fbsd-alpha
WORDSIZE=	64
.endif

.if !defined(TARGET)
pre-fetch:
	@${ECHO_MSG} "Cannot determine M3 target for this architecture"
	@${FALSE}
.endif

do-build:
	@${ECHO_MSG} "This port does everything in the install step."
	@${ECHO_MSG} "The build step is a no-op."

do-install:
	@for i in ${BUILDDIRS}; do \
	    ${ECHO_MSG} "Building in $${i}"; \
	    cd ${WRKSRC}/$${i} && ${PREFIX}/bin/m3build && \
		${PREFIX}/bin/m3ship; \
	done
	@for i in ${PROGS}; do ${STRIP_CMD} ${PREFIX}/$$i; done
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/${PORTNAME}

.include <bsd.port.post.mk>
