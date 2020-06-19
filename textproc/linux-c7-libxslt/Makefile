# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	libxslt
PORTVERSION=	1.1.28
DISTVERSIONSUFFIX=	-5.el7
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XSLT C library for GNOME (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
SRC_DISTFILES=

DESCR=		${.CURDIR:H}/${PORTNAME}/pkg-descr
LIBDIR=		usr/lib${ARCH:S/i386//:S/amd64/64/}
PLIST_FILES=	${LIBDIR}/libxslt.so.${PORTVERSION} ${LIBDIR}/libxslt.so.1 \
		${LIBDIR}/libexslt.so.0.8.17 ${LIBDIR}/libexslt.so.0

# Note, that we do not install the /usr/bin/xsltproc -- use FreeBSD's
# own compiled executable, if you need it.

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBDIR}
	${LN} ${WRKSRC}/${LIBDIR}/libxslt.so.${PORTVERSION}	\
	    ${WRKSRC}/${LIBDIR}/libexslt.so.0.8.17	\
		${STAGEDIR}${PREFIX}/${LIBDIR}
	${LN} -s libxslt.so.${PORTVERSION}	\
		${STAGEDIR}${PREFIX}/${LIBDIR}/libxslt.so.1
	${LN} -s libexslt.so.0.8.17 \
		${STAGEDIR}${PREFIX}/${LIBDIR}/libexslt.so.0

.include <bsd.port.mk>
