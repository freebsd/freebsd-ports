# New ports collection makefile for:	libdvdread
# Date created:				24 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdread
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	This is needed by ogle, which is a DVD player that supports DVD menus

LIB_DEPENDS=	dvdcss.${DVDCSS_LIBVERSION}:${PORTSDIR}/multimedia/libdvdcss

GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

DOC_FILES=	AUTHORS COPYING NEWS README TODO

# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--disable-warnings
.endif

# ugly hack to have libdvdread directly depend on libdvdcss since
# it already does for practical reasons even though not for compile
# time ones
DVDCSS_LIBVERSION=	2

post-patch:
.for p in Makefile.in dvdread/Makefile.in src/Makefile.in
	@${REINPLACE_CMD} -E -e 's|cd \$$\(top_srcdir\) && \$$\(AUTOMAKE\)|\#|; \
		s|cd \$$\(srcdir\) && \$$\(ACLOCAL\)|\#|' ${WRKSRC}/${p}
.endfor
# update this in sync with libdvdcss shared library version
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so).2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/dvdread/dvd_input.c

post-configure:
	@${LN} -sf ${LIBTOOL} ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

# FreeBSD byteswap optimized routines
.if ${ARCH} == "i386"
. if (defined(MACHINE_CPU) && ${MACHINE_CPU:Mi486} == "i486")
WITH_OPTIMIZED_BYTESWAP=yes
. endif

. if defined(WITH_OPTIMIZED_BYTESWAP)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-dvdread::bswap.h
. endif
.endif

pre-everything::
.ifndef(WITH_OPTIMIZED_BYTESWAP)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_OPTIMIZED_BYTESWAP to use optimized byteswap'
	@${ECHO_MSG} '===> routines. This works only in the i386 architecture, and'
	@${ECHO_MSG} '===> only with 486 processors and above.'
.endif

.include <bsd.port.post.mk>
