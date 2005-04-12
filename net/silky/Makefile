# New ports collection makefile for:	silky
# Date created:				2003.12.16
# Whom:					Evgueni V. Gavrilov <aquatique@rusunix.org>
#
# $FreeBSD$
#

PORTNAME=	silky
PORTVERSION=	0.5.4
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://rusunix.org/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	silky

MAINTAINER=	aquatique-ports@rambler.ru
COMMENT=	A simple and easy to use graphical, os-independent SILC client

LIB_DEPENDS=	silcclient-1.0.3:${PORTSDIR}/devel/silc-toolkit
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-silc-include=${LOCALBASE}/include/silc \
		--with-silc-libs=${LOCALBASE}/lib \
		--with-docdir=${DOCSDIR} \
		--with-libintl-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

USE_GNOME=	gtk20 libglade2 gnomelibs
USE_GMAKE=	yes
USE_PERL5=	yes
USE_X_PREFIX=	yes

post-patch:
	@${PERL} -pi -e 's/ include / /' ${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's|share/pixmaps/\$${\w+}|share/pixmaps/|; \
			s|(PACKAGE_PIXMAPS_DIR \")\$${packageprefix}/|\1${X11BASE}/|' \
	    ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
