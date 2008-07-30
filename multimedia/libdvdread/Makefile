# New ports collection makefile for:	libdvdread
# Date created:				24 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdread
PORTVERSION=	0.9.7
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	This is needed by ogle, which is a DVD player that supports DVD menus

.if !defined(PACKAGE_BUILDING)
LIB_DEPENDS=	dvdcss.${DVDCSS_LIBVERSION}:${PORTSDIR}/multimedia/libdvdcss
.endif

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

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

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
