# New ports collection makefile for:	mozilla-bonobo
# Date created:			20 Nov 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		mozilla-bonobo
PORTVERSION=		0.4.0
PORTREVISION=	1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	moz-bonobo

MAINTAINER=		jylefort@brutele.be
COMMENT=		A Netscape/Mozilla plugin using Bonobo controls to display files

BUILD_DEPENDS=		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=		mozilla-gtk2
HEADERS_SUFX=

.if !defined(WITH_MOZILLA)
MOZILLA=		mozilla-gtk2
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=		${WITH_MOZILLA}
HEADERS_SUFX=		-devel
.else
MOZILLA=		mozilla-gtk2
HEADERS_SUFX=
.endif
.endif

USE_X_PREFIX=		yes
USE_GNOME=		gnomeprefix libgnomeui libgnomeprint
USE_LIBTOOL_VER=	15
USE_REINPLACE=		yes

CONFIGURE_ARGS=		--with-plugin-install-dir="${PREFIX}/lib/browser_plugins" \
			--with-mozilla-include-dir="${X11BASE}/include/mozilla${HEADERS_SUFX}"

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default mozilla-bonobo uses www/mozilla-gtk2 for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  mozilla-devel-gtk2 "
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e \
		's|\$${prefix}/doc/mozilla-bonobo|${DOCSDIR}| ; \
		 s|COPYING\\|\\| ; \
		 s|INSTALL\\|\\| ; \
		 s|TODO\\|TODO| ; \
		 s|ABOUT-NLS||' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e \
		's|\$$(libmozilla_bonobodoc_DATA)|| ; \
		 s|\$$(mkinstalldirs) \$$(DESTDIR)\$$(libmozilla_bonobodocdir)||
; \
		 s| \$$(DESTDIR)\$$(libmozilla_bonobodocdir) | |' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
