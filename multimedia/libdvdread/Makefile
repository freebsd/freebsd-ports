# New ports collection makefile for:	libdvdread
# Date created:				24 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdread
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	3d@FreeBSD.org

LIB_DEPENDS=	dvdcss.${DVDCSS_LIBVERSION}:${PORTSDIR}/graphics/libdvdcss

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

DOC_FILES=	AUTHORS NEWS README TODO

# ugly hack to have libdvdread directly depend on libdvdcss since
# it already does for practical reasons even though not for compile
# time ones
DVDCSS_LIBVERSION=	2

# optional CFLAGS safeness
.if !defined(WITH_OPTIMIZED_CFLAGS)
USE_AUTOCONF=	yes
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure.in
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "====> If you want to enable optimizations, please define WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
.for p in Makefile.in dvdread/Makefile.in src/Makefile.in
	@${PERL} -pi -e 's|cd \$$\(top_srcdir\) && \$$\(AUTOMAKE\)|\#|; \
		s|cd \$$\(srcdir\) && \$$\(ACLOCAL\)|\#|' ${WRKSRC}/${p}
.endfor
# update this in sync with libdvdcss shared library version
	@${PERL} -pi -e 's|(libdvdcss.so).0|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/dvdread/dvd_reader.c

post-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
