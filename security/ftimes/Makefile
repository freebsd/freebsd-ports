# Created by: Klayton Monroe <klm@uidzero.org>
# $FreeBSD$

PORTNAME=		ftimes
PORTVERSION=		3.8.0
PORTREVISION=		1
CATEGORIES=		security sysutils
MASTER_SITES=		SF
EXTRACT_SUFX=		.tgz

MAINTAINER=		klm@uidzero.org
COMMENT=		System baselining and evidence collection tool

GNU_CONFIGURE=		yes
USE_PERL5=		yes

MAN1=			ftimes.1

OPTIONS_DEFINE=	DIG_TOOLS HASHDIG_TOOLS MAP_TOOLS PCRE SSL XMAGIC
OPTIONS_DEFAULT=	DIG_TOOLS HASHDIG_TOOLS MAP_TOOLS PCRE SSL XMAGIC
DIG_TOOLS_DESC=		install dig tools
HASHDIG_TOOLS_DESC=	install hashdig tools
MAP_TOOLS_DESC=		install map tools
XMAGIC_DESC=		XMagic support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDIG_TOOLS} || ${PORT_OPTIONS:MMAP_TOOLS}
. if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5
. endif
.endif

.if ${PORT_OPTIONS:MDIG_TOOLS}
PLIST_SUB+=		DIG_TOOLS=""
CONFIGURE_ARGS+=	--with-dig-tools
MAN1+=			ftimes-crv2dbi.1 ftimes-crv2raw.1 ftimes-dig2ctx.1 ftimes-dig2dbi.1 hipdig.1
RUN_DEPENDS+=		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
.else
PLIST_SUB+=		DIG_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MHASHDIG_TOOLS}
PLIST_SUB+=		HASHDIG_TOOLS=""
CONFIGURE_ARGS+=	--with-hashdig-tools
MAN1+=			hashdig-bash.1 hashdig-bind.1 hashdig-dump.1 hashdig-find.1 hashdig-filter.1 hashdig-harvest-sunsolve.1 hashdig-harvest.1 hashdig-make.1 hashdig-resolve-sunsolve.1 hashdig-stat.1 hashdig-weed.1
.else
PLIST_SUB+=		HASHDIG_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MMAP_TOOLS}
PLIST_SUB+=		MAP_TOOLS=""
CONFIGURE_ARGS+=	--with-map-tools
MAN1+=			ftimes-cmp2dbi.1 ftimes-map2dbi.1 ftimes-map2mac.1 tarmap.1
.else
PLIST_SUB+=		MAP_TOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=		pcre.3:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-pcre
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

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ftimes

.include <bsd.port.post.mk>
