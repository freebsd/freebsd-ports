# Created by: Klayton Monroe <klm@uidzero.org>
# $FreeBSD$

PORTNAME=		ftimes
PORTVERSION=		3.10.0
CATEGORIES=		security sysutils
MASTER_SITES=		SF
EXTRACT_SUFX=		.tgz

MAINTAINER=		klm@uidzero.org
COMMENT=		System baselining and evidence collection tool

LICENSE=		BSD APACHE20 MIT
LICENSE_COMB=		multi

GNU_CONFIGURE=		yes
USES=			perl5

MAN1=			ftimes.1
MAN3=			FTimes::EadRoutines.3 FTimes::Properties.3

OPTIONS_DEFINE=		DBM_TOOLS DIG_TOOLS FILE_HOOKS HASHDIG_TOOLS MAP_TOOLS SSL XMAGIC
OPTIONS_DEFAULT=	DBM_TOOLS DIG_TOOLS FILE_HOOKS HASHDIG_TOOLS MAP_TOOLS SSL XMAGIC
DBM_TOOLS_DESC=		Install DBM tools
DIG_TOOLS_DESC=		Install dig tools
FILE_HOOKS_DESC=	Include file hooks support
HASHDIG_TOOLS_DESC=	Install hashdig tools
MAP_TOOLS_DESC=		Install map tools
XMAGIC_DESC=		XMagic support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

LIB_DEPENDS+=		pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}

STRIP_FILES=		${PREFIX}/bin/ftimes

.if ${PORT_OPTIONS:MDBM_TOOLS}
PLIST_SUB+=		DBM_TOOLS=""
CONFIGURE_ARGS+=	--with-dbm-tools
MAN1+=			ftimes-dbm-bash.1 ftimes-dbm-dump.1 ftimes-dbm-find.1 ftimes-dbm-make.1 ftimes-dbm-reap.1 ftimes-dbm-weed.1
.else
PLIST_SUB+=		DBM_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MDIG_TOOLS}
PLIST_SUB+=		DIG_TOOLS=""
CONFIGURE_ARGS+=	--with-dig-tools
MAN1+=			ftimes-crv2dbi.1 ftimes-crv2raw.1 ftimes-dig2ctx.1 ftimes-dig2dbi.1 hipdig.1
RUN_DEPENDS+=		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
.else
PLIST_SUB+=		DIG_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MFILE_HOOKS}
LIB_DEPENDS+=		klel:${PORTSDIR}/devel/libklel
CONFIGURE_ARGS+=	--enable-file-hooks --with-klel=${LOCALBASE} --with-perl=${LOCALBASE}/bin/perl
.else
PLIST_SUB+=		WITH_FILE_HOOKS="@comment "
.endif

.if ${PORT_OPTIONS:MHASHDIG_TOOLS}
PLIST_SUB+=		HASHDIG_TOOLS=""
CONFIGURE_ARGS+=	--with-hashdig-tools
MAN1+=			hashdig-bash.1 hashdig-bind.1 hashdig-dump.1 hashdig-filter.1 hashdig-find.1 hashdig-harvest.1 hashdig-harvest-sunsolve.1 hashdig-make.1 hashdig-resolve-sunsolve.1 hashdig-stat.1 hashdig-weed.1
.else
PLIST_SUB+=		HASHDIG_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MMAP_TOOLS}
PLIST_SUB+=		MAP_TOOLS=""
CONFIGURE_ARGS+=	--with-map-tools
MAN1+=			ftimes-cat.1 ftimes-cmp2dbi.1 ftimes-cmp2diff.1 ftimes-encoder.1 ftimes-grabber.1 ftimes-map2dbi.1 ftimes-map2mac.1 ftimes-proximo.1 ftimes-sizimus.1 ftimes-sortini.1 ftimes-xformer.1 ftimes-xpa.1 hashcp.1 tarmap.1 zipmap.1
STRIP_FILES+=		${PREFIX}/bin/ftimes-cat ${PREFIX}/bin/ftimes-xpa ${PREFIX}/bin/hashcp ${PREFIX}/bin/tarmap
.else
PLIST_SUB+=		MAP_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if ${PORT_OPTIONS:MXMAGIC}
PLIST_SUB+=		XMAGIC=""
CONFIGURE_ARGS+=	--enable-xmagic
.else
PLIST_SUB+=		XMAGIC="@comment "
.endif

post-configure:
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' ${WRKSRC}/lib/perl/Makefile

post-install:
	${STRIP_CMD} ${STRIP_FILES}

.include <bsd.port.post.mk>
