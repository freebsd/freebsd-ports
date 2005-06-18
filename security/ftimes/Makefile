# New ports collection makefile for:	ftimes
# Date created:		20 August 2002
# Whom:			Klayton Monroe <klm@uidzero.org>
#
# $FreeBSD$
#

PORTNAME=		ftimes
PORTVERSION=		3.5.0
CATEGORIES=		security sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ftimes
EXTRACT_SUFX=		.tgz

MAINTAINER=		klm@uidzero.org
COMMENT=		A system baselining and evidence collection tool

GNU_CONFIGURE=		yes
USE_PERL5_RUN=		yes

MAN1=			ftimes.1

OPTIONS=		DIG_TOOLS "install dig tools" on \
			HASHDIG_TOOLS "install hashdig tools" on \
			MAP_TOOLS "install map tools" on \
			PCRE "PCRE support" on \
			SSL "OpenSSL support" on

.include <bsd.port.pre.mk>

.if defined(WITH_DIG_TOOLS)
PLIST_SUB+=		DIG_TOOLS=""
CONFIGURE_ARGS+=	--with-dig-tools
.else
PLIST_SUB+=		DIG_TOOLS="@comment "
.endif

.if defined(WITH_HASHDIG_TOOLS)
PLIST_SUB+=		HASHDIG_TOOLS=""
CONFIGURE_ARGS+=	--with-hashdig-tools
.else
PLIST_SUB+=		HASHDIG_TOOLS="@comment "
.endif

.if defined(WITH_MAP_TOOLS)
PLIST_SUB+=		MAP_TOOLS=""
CONFIGURE_ARGS+=	--with-map-tools
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

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ftimes

.include <bsd.port.post.mk>
