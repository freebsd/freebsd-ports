# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-fonts/fontconfig/Makefile 18637 2013-07-27 09:15:21Z kwm $

PORTNAME=	fontconfig
PORTVERSION=	2.10.93
PORTREVISION?=	0
PORTEPOCH?=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.freedesktop.org/software/fontconfig/release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An XML-based font configuration API for X Windows

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USES=		gmake pathfix pkgconfig
USE_GNOME=	ltverhack
CONFIGURE_ARGS=	--with-configdir=${PREFIX}/etc/fonts/conf.d \
		--with-templatedir=${PREFIX}/etc/fonts/conf.avail \
		--with-xmldir=${PREFIX}/etc/fonts \
		--with-expat-includes=${LOCALBASE}/include \
		--with-expat-lib=${LOCALBASE}/lib \
		--with-default-fonts=${PREFIX}/share/fonts \
		--with-add-fonts=${LOCALBASE}/lib/X11/fonts \
		--with-cache-dir=/var/db/fontconfig \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--disable-docs
MAKE_ENV=	LC_ALL=C
PKGINSTALL=	${WRKDIR}/pkg-install

MAN1=		fc-cache.1 fc-cat.1 fc-list.1 fc-match.1 fc-query.1 fc-scan.1
MAN5=		fonts-conf.5
PORTDOCS=	fontconfig-user.html fontconfig-user.pdf fontconfig-user.txt

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif
	${INSTALL_MAN} ${MAN5:S|^|${WRKSRC}/doc/|} ${PREFIX}/man/man5
.for manpage in ${MAN1}
	${INSTALL_MAN} ${FILESDIR}/${manpage} ${PREFIX}/man/man1
.endfor
	if [ ! -f ${PREFIX}/etc/fonts/fonts.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/fonts.conf ${PREFIX}/etc/fonts/fonts.conf; \
		${INSTALL_DATA} ${WRKSRC}/fonts.conf ${PREFIX}/etc/fonts/fonts.conf.default; \
	else \
		${INSTALL_DATA} ${WRKSRC}/fonts.conf ${PREFIX}/etc/fonts/fonts.conf.default; \
	fi
	@${SED} -e 's|%%PREFIX%%|${PREFIX}| ; \
		s|%%LOCALBASE%%|${LOCALBASE}|' < ${FILESDIR}/pkg-install.in \
		> ${PKGINSTALL}
.if !defined(PACKAGE_BUILDING)
	-@${LDCONFIG} -m ${PREFIX}/lib
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>

.endif
