# Created by: Klayton Monroe <klm@uidzero.org>
# $FreeBSD$

PORTNAME=		ftimes
PORTVERSION=		3.11.0
PORTREVISION=	2
CATEGORIES=		security sysutils
MASTER_SITES=		SF

MAINTAINER=		klm@uidzero.org
COMMENT=		System baselining and evidence collection tool

LICENSE=		BSD3CLAUSE APACHE20 MIT
LICENSE_COMB=		multi

BROKEN_aarch64=		fails to build: aarch64 is not currently supported
BROKEN_mips64=		fails to build: mips64 is not currently supported

GNU_CONFIGURE=		yes
USES=			perl5 shebangfix tar:tgz
USE_PERL5=		run build
SHEBANG_FILES= \
			${WRKSRC}/tools/dig/ftimes-crv2dbi.pl \
			${WRKSRC}/tools/dig/ftimes-crv2raw.pl \
			${WRKSRC}/tools/dig/ftimes-dig2ctx.pl \
			${WRKSRC}/tools/dig/ftimes-dig2dbi.pl \
			${WRKSRC}/tools/dig/hipdig.pl \
			${WRKSRC}/tools/ftimes-bimvl/ftimes-bimvl \
			${WRKSRC}/tools/ftimes-cmp2diff/ftimes-cmp2diff \
			${WRKSRC}/tools/ftimes-dbm-bash/ftimes-dbm-bash \
			${WRKSRC}/tools/ftimes-dbm-dump/ftimes-dbm-dump \
			${WRKSRC}/tools/ftimes-dbm-find/ftimes-dbm-find \
			${WRKSRC}/tools/ftimes-dbm-make/ftimes-dbm-make \
			${WRKSRC}/tools/ftimes-dbm-reap/ftimes-dbm-reap \
			${WRKSRC}/tools/ftimes-dbm-weed/ftimes-dbm-weed \
			${WRKSRC}/tools/ftimes-encoder/ftimes-encoder \
			${WRKSRC}/tools/ftimes-grabber/ftimes-grabber \
			${WRKSRC}/tools/ftimes-proximo/ftimes-proximo \
			${WRKSRC}/tools/ftimes-sizimus/ftimes-sizimus \
			${WRKSRC}/tools/ftimes-sortini/ftimes-sortini \
			${WRKSRC}/tools/ftimes-xformer/ftimes-xformer \
			${WRKSRC}/tools/hashdig/hashdig-bash.pl \
			${WRKSRC}/tools/hashdig/hashdig-bind.pl \
			${WRKSRC}/tools/hashdig/hashdig-dump.pl \
			${WRKSRC}/tools/hashdig/hashdig-filter.pl \
			${WRKSRC}/tools/hashdig/hashdig-find.pl \
			${WRKSRC}/tools/hashdig/hashdig-harvest-sunsolve.pl \
			${WRKSRC}/tools/hashdig/hashdig-harvest.pl \
			${WRKSRC}/tools/hashdig/hashdig-make.pl \
			${WRKSRC}/tools/hashdig/hashdig-resolve-sunsolve.pl \
			${WRKSRC}/tools/hashdig/hashdig-stat.pl \
			${WRKSRC}/tools/hashdig/hashdig-weed.pl \
			${WRKSRC}/tools/map/ftimes-cmp2dbi.pl \
			${WRKSRC}/tools/map/ftimes-map2dbi.pl \
			${WRKSRC}/tools/map/ftimes-map2mac.pl \
			${WRKSRC}/tools/zipmap/zipmap

OPTIONS_DEFINE=		DBM_TOOLS DIG_TOOLS FILE_HOOKS HASHDIG_TOOLS MAP_TOOLS SSL XMAGIC
OPTIONS_DEFAULT=	DBM_TOOLS DIG_TOOLS FILE_HOOKS HASHDIG_TOOLS MAP_TOOLS XMAGIC
DBM_TOOLS_DESC=		Install DBM tools
DIG_TOOLS_DESC=		Install dig tools
FILE_HOOKS_DESC=	Include file hooks support
HASHDIG_TOOLS_DESC=	Install hashdig tools
MAP_TOOLS_DESC=		Install map tools
XMAGIC_DESC=		XMagic support

SSL_USES=	ssl

.include <bsd.port.pre.mk>

LIB_DEPENDS+=		libpcre.so:devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}

STRIP_FILES=		${STAGEDIR}${PREFIX}/bin/ftimes

INSTALL_PERL5_LIBS=

.if ${PORT_OPTIONS:MDBM_TOOLS}
PLIST_SUB+=		DBM_TOOLS=""
CONFIGURE_ARGS+=	--with-dbm-tools
.else
PLIST_SUB+=		DBM_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MDIG_TOOLS}
PLIST_SUB+=		DIG_TOOLS=""
CONFIGURE_ARGS+=	--with-dig-tools
RUN_DEPENDS+=		p5-Digest-SHA1>=0:security/p5-Digest-SHA1
INSTALL_PERL5_LIBS=	yes
.else
PLIST_SUB+=		DIG_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MFILE_HOOKS}
LIB_DEPENDS+=		libklel.so:devel/libklel
CONFIGURE_ARGS+=	--enable-file-hooks --with-klel=${LOCALBASE} --with-perl=${LOCALBASE}/bin/perl
.else
PLIST_SUB+=		WITH_FILE_HOOKS="@comment "
.endif

.if ${PORT_OPTIONS:MHASHDIG_TOOLS}
PLIST_SUB+=		HASHDIG_TOOLS=""
CONFIGURE_ARGS+=	--with-hashdig-tools
.else
PLIST_SUB+=		HASHDIG_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MMAP_TOOLS}
PLIST_SUB+=		MAP_TOOLS=""
CONFIGURE_ARGS+=	--with-map-tools
STRIP_FILES+=		${STAGEDIR}${PREFIX}/bin/ftimes-cat ${STAGEDIR}${PREFIX}/bin/ftimes-xpa ${STAGEDIR}${PREFIX}/bin/hashcp ${STAGEDIR}${PREFIX}/bin/tarmap
INSTALL_PERL5_LIBS=	yes
.else
PLIST_SUB+=		MAP_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if ${PORT_OPTIONS:MXMAGIC}
PLIST_SUB+=		XMAGIC=""
CONFIGURE_ARGS+=	--enable-xmagic
.else
PLIST_SUB+=		XMAGIC="@comment "
CONFIGURE_ARGS+=	--disable-xmagic
.endif

.if ${INSTALL_PERL5_LIBS}
PLIST_SUB+=		FTIMES_PERL5_LIBS=""
.else
PLIST_SUB+=		FTIMES_PERL5_LIBS="@comment "
.endif

post-configure:
	if [ "${INSTALL_PERL5_LIBS}" = "yes" ] ; then ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' ${WRKSRC}/lib/perl/Makefile ; fi

post-install:
	${STRIP_CMD} ${STRIP_FILES}

.include <bsd.port.post.mk>
