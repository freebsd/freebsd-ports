# New ports collection makefile for:	papaya
# Date created:		23 August 2001
# Whom:			Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	papaya
PORTVERSION=	0.90
CATEGORIES=	net
MASTER_SITES=	http://www.gtk-papaya.org/downloads/source/
DISTNAME=	papaya-src-${PORTVERSION}

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	Graphical GTK mud client with plugin support

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
USE_PERL=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomeprefix gnomehack gnomelibs
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

CONFIGURE_ENV+=	GLIBCONFIG=${GLIB_CONFIG} GTKCONFIG=${GTK_CONFIG}
MAKE_ARGS+=	PTHREAD_LIBS=${PTHREAD_LIBS} CXX="${CXX}"

post-patch:
	@${PERL} -pi -e "s|/usr/local|${PREFIX}|"  \
		${WRKSRC}/src/install-system.sh
	@${PERL} -pi -e "s|\@INSTALL\@|${INSTALL_PROGRAM}|g; \
		s|\@INSTALL_DATA\@|${INSTALL_DATA}|g" \
		${WRKSRC}/src/install-system.sh ${WRKSRC}/po/Makefile.in.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
