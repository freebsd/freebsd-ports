PORTNAME=	milter-manager
DISTVERSION=	2.1.6
PORTREVISION=	2
CATEGORIES=	mail ruby
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Super milter that can invoke several milters selectively
WWW=		https://milter-manager.osdn.jp/

LICENSE=	AGPLv3 GFDL GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	rubygem-gio2>0:devel/rubygem-gio2
LIB_DEPENDS=	libev.so:devel/libev
RUN_DEPENDS=	rubygem-gio2>0:devel/rubygem-gio2 \
		rubygem-rexml>0:textproc/rubygem-rexml

USES=		compiler:c++11-lang gettext gmake gnome libtool localbase \
		pathfix pkgconfig ruby
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes
USE_RC_SUBR=	milter-manager

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--with-libev \
		--with-package-platform=freebsd

INSTALL_TARGET=	install-strip

CFLAGS+=	-fdeclspec

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.in -exec \
	${REINPLACE_CMD} -e "s#\$$(datadir)/@PACKAGE@#${DATADIR}#" \
			 -e "s#\$$(datarootdir)/\$$(PACKAGE)#${DATADIR}#" {} +
	@${REINPLACE_CMD} -e "s#\\\\\$$(pkgdatadir)/sample#${EXAMPLESDIR}#" ${WRKSRC}/configure

.include <bsd.port.post.mk>
