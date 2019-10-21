# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	miracl
PORTVERSION=	5.6
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		LOCAL/jase

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprecision Integer and Rational Arithmetic C/C++ Library

LICENSE=	AGPLv3 COMMERCIAL
LICENSE_COMB=	dual
LICENSE_NAME_COMMERCIAL=	Commercial use license to not be bound by AGPLv3
LICENSE_TEXT_COMMERCIAL=	License available from CertiVox for commercial use and
LICENSE_TEXT_COMMERCIAL+=	to not be bound by the terms of the AGPLv3. Visit
LICENSE_TEXT_COMMERCIAL+=	http://certivox.com/index.php/solutions/miracl-crypto-sdk/
LICENSE_TEXT_COMMERCIAL+=	for more details.
#LICENSE_FILE=			${FILESDIR}/LICENSE
LICENSE_PERMS_COMMERCIAL=	dist-mirror dist-sell pkg-mirror pkg-sell no-auto-accept

ONLY_FOR_ARCHS=	i386 amd64

USES=		zip
USE_GCC=	yes
USE_LDCONFIG=	yes

EXTRACT_BEFORE_ARGS=	-j -L -q
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

PLIST_FILES=	lib/libmiracl.a \
		include/miracl.h include/mirdef.h

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
BUILDCMD=	linux
.elif ${ARCH} == "amd64"
BUILDCMD=	linux64
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
# C{C,XX} safeness
# CFLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|gcc|${CC}|' \
		-e 's|g\+\+|${CXX}|' \
		-e 's|-O2|${CFLAGS}|' \
		${WRKSRC}/${BUILDCMD}
# Don't error when files not found
# Fix mrmuldv.cc not existing due to s/gcc/CC/ replacement above.
	@${REINPLACE_CMD} -E \
		-e 's|^rm |${RM} |' \
		-e 's|^cp mrmuldv\.${CC} mrmuldv\.c|${CP} mrmuldv.gcc mrmuldv.c|' \
		${WRKSRC}/${BUILDCMD}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} -ve ./${BUILDCMD}

do-install:
# lib
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.a \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.a
# headers
	@${INSTALL_DATA} ${WRKSRC}/miracl.h \
		${STAGEDIR}${PREFIX}/include/miracl.h
	@${INSTALL_DATA} ${WRKSRC}/mirdef.h \
		${STAGEDIR}${PREFIX}/include/mirdef.h

.include <bsd.port.mk>
