# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-doc-utils
PORTVERSION=	1.6.2
CATEGORIES=	textproc mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE doc utils

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian \
		${LOCALBASE}/share/xml/docbook/4.3/catalog.xml:${PORTSDIR}/textproc/docbook-xml-430 \
		${LOCALBASE}/share/xml/docbook/4.4/catalog.xml:${PORTSDIR}/textproc/docbook-xml-440 \
		xml2po:${PORTSDIR}/textproc/gnome-doc-utils

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build intlhack
USE_GNOME=	gnomehier libxml2 libxslt
USE_PYTHON=	build
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
CONFIGURE_ARGS=--with-omf-dir=${PREFIX}/share/omf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

post-patch:
	@${REINPLACE_CMD} -e 's|-W compat|--traditional|g' \
		${WRKSRC}/configure.ac
	@${CHMOD} +x ${WRKSRC}/autogen.sh

pre-install:
	@${REINPLACE_CMD} -e 's|build_SUBDIRS = xml2po|build_SUBDIRS =|g ; \
		s|po rng xslt|po xslt|g' \
			${WRKSRC}/Makefile

.include <bsd.port.mk>
