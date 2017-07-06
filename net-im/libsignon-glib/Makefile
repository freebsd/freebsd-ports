# $FreeBSD$

PORTNAME=	${GL_PROJECT}
PORTVERSION=	1.14
CATEGORIES=	net-im
MASTER_SITES=	https://gitlab.com/${GL_ACCOUNT}/${GL_PROJECT}/repository/archive${EXTRACT_SUFX}?ref=${GL_TAGNAME}&num;/ \
		LOCAL/tcberner/${GL_ACCOUNT}/
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GLib-based client library for applications handling account authentication

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc \
		signond:sysutils/signon-qt5
RUN_DEPENDS=	signond:sysutils/signon-qt5

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-tests --enable-gtk-doc

USES=		autoreconf gmake libtool pathfix pkgconfig python tar:bz2
USE_GNOME=	introspection pygobject3

PATHFIX_MAKEFILEIN=	Makefile.am

# gitlab variables
GL_ACCOUNT=	accounts-sso
GL_PROJECT=	libsignon-glib
GL_TAGNAME=	4e85baaf483268d04bbf835bebeac4ae30c7c327
WRKSRC=		${WRKDIR}/${GL_PROJECT}-${GL_TAGNAME}-${GL_TAGNAME}

# Run gtdocize as done in autogen.sh
pre-configure:
	cd ${CONFIGURE_WRKSRC} && gtkdocize --copy --flavour no-tmpl

.include <bsd.port.mk>
