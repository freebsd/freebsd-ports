PORTNAME=	milter-manager
DISTVERSION=	2.1.6
CATEGORIES=	mail ruby
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Super milter that can invoke several milters selectively

LICENSE=	AGPLv3 GFDL GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	rubygem-gio2>0:devel/rubygem-gio2
LIB_DEPENDS=	libev.so:devel/libev
RUN_DEPENDS=	rubygem-gio2>0:devel/rubygem-gio2

USES=		compiler:c++11-lang gettext gmake gnome libtool pathfix \
		pkgconfig
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes
USE_RC_SUBR=	milter-manager
USE_RUBY=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--with-libev \
		--with-package-platform=freebsd

INSTALL_TARGET=	install-strip

CFLAGS+=	-fdeclspec
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.in -exec \
	${REINPLACE_CMD} -e "s#\$$(datadir)/@PACKAGE@#${DATADIR}#" \
			 -e "s#\$$(datarootdir)/\$$(PACKAGE)#${DATADIR}#" {} +
	@${REINPLACE_CMD} -e "s#\\\\\$$(pkgdatadir)/sample#${EXAMPLESDIR}#" ${WRKSRC}/configure
	@${RM} -r ${WRKSRC}/binding/ruby/glib-2.2.5

.include <bsd.port.mk>
