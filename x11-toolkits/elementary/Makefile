# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	1.7.9
CATEGORIES=	x11-toolkits enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Simple widget toolkit using EFL

LICENSE=	LGPL21

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_EFL=	ecore eio edbus efreet embryo edje emotion ethumb \
		libtool_hack librt_hack modarch_hack
USE_LUA=	5.1+
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--disable-quick-launch

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CONFIGURE_ARGS+=--enable-install-examples
.else
CONFIGURE_ARGS+=--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(pkgdatadir)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in
	@${LN} -s profile.src ${WRKSRC}/config/profile.cfg
	@${LN} -s base.src ${WRKSRC}/config/default/base.cfg
	@${LN} -s base.src ${WRKSRC}/config/mobile/base.cfg
	@${LN} -s base.src ${WRKSRC}/config/standard/base.cfg

post-install:
.if empty(PORT_OPTIONS:MEXAMPLES)
	@${RMDIR} ${EXAMPLESDIR}
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: signal 10
.endif

.include <bsd.port.mk>
