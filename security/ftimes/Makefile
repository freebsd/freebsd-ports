# New ports collection makefile for:	ftimes
# Date created:		20 August 2002
# Whom:			Klayton Monroe <klm@uidzero.org>
#
# $FreeBSD$
#

PORTNAME=		ftimes
PORTVERSION=		3.8.0
CATEGORIES=		security sysutils
MASTER_SITES=		SF
EXTRACT_SUFX=		.tgz

MAINTAINER=		klm@uidzero.org
COMMENT=		A system baselining and evidence collection tool

GNU_CONFIGURE=		yes
USE_PERL5=		yes

MAN1=			ftimes.1

OPTIONS=		DIG_TOOLS "install dig tools" on \
			HASHDIG_TOOLS "install hashdig tools" on \
			MAP_TOOLS "install map tools" on \
			PCRE "PCRE support" on \
			SSL "OpenSSL support" on \
			XMAGIC "XMagic support" on

.include <bsd.port.pre.mk>

.if defined(WITH_DIG_TOOLS) || defined(WITH_MAP_TOOLS)
RUN_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

.if defined(WITH_DIG_TOOLS)
PLIST_SUB+=		DIG_TOOLS=""
CONFIGURE_ARGS+=	--with-dig-tools
MAN1+=			ftimes-crv2dbi.1 ftimes-crv2raw.1 ftimes-dig2ctx.1 ftimes-dig2dbi.1 hipdig.1
RUN_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
.else
PLIST_SUB+=		DIG_TOOLS="@comment "
.endif

.if defined(WITH_HASHDIG_TOOLS)
PLIST_SUB+=		HASHDIG_TOOLS=""
CONFIGURE_ARGS+=	--with-hashdig-tools
MAN1+=			hashdig-bash.1 hashdig-bind.1 hashdig-dump.1 hashdig-find.1 hashdig-filter.1 hashdig-harvest-sunsolve.1 hashdig-harvest.1 hashdig-make.1 hashdig-resolve-sunsolve.1 hashdig-stat.1 hashdig-weed.1
.else
PLIST_SUB+=		HASHDIG_TOOLS="@comment "
.endif

.if defined(WITH_MAP_TOOLS)
PLIST_SUB+=		MAP_TOOLS=""
CONFIGURE_ARGS+=	--with-map-tools
MAN1+=			ftimes-cmp2dbi.1 ftimes-map2dbi.1 ftimes-map2mac.1 tarmap.1
.else
PLIST_SUB+=		MAP_TOOLS="@comment "
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=		pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if defined(WITH_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(WITH_XMAGIC)
PLIST_SUB+=		XMAGIC=""
CONFIGURE_ARGS+=	--enable-xmagic
.else
PLIST_SUB+=		XMAGIC="@comment "
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ftimes

.include <bsd.port.post.mk>
