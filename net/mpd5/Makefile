# Created by: Archie Cobbs
# $FreeBSD$

PORTNAME=	mpd
DISTVERSION=	5.8
PORTREVISION=	10
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Mpd5/Mpd-${PORTVERSION}
PKGNAMESUFFIX=	5
DIST_SUBDIR=	mpd5

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Multi-link PPP daemon based on netgraph(4)

LICENSE=	BSD3CLAUSE

BROKEN_SSL=	libressl libressl-devel
BROKEN_SSL_REASON_libressl=		needs libfetch(3) linked with system libssl
BROKEN_SSL_REASON_libressl-devel=	needs libfetch(3) linked with system libssl

OPTIONS_DEFINE=	DOCS NG_IPACCT
NG_IPACCT_DESC=	Use ng_ipacct kernel module from port

HAS_CONFIGURE=	YES
CONFIGURE_WRKSRC=	"${WRKSRC}/src"

USES=		ssl

.include <bsd.port.options.mk>

MAKE_ARGS+=	OSVERSION=${OSVERSION}

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} < 1200085
BROKEN_SSL+=	openssl111
BROKEN_SSL_REASON_openssl111=	needs libfetch(3) linked with system libssl
.endif

.if ${PORT_OPTIONS:MNG_IPACCT}
BUILD_DEPENDS+=	${LOCALBASE}/include/netgraph/ng_ipacct.h:net-mgmt/ng_ipacct
.if exists(${KMODDIR}/ng_ipacct.ko)
RUN_DEPENDS+=	${KMODDIR}/ng_ipacct.ko:net-mgmt/ng_ipacct
.else
RUN_DEPENDS+=	/boot/modules/ng_ipacct.ko:net-mgmt/ng_ipacct
.endif
.else
CONFIGURE_ENV+=	USE_NG_IPACCT=no
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-no-ng_ipacct
.endif

USE_RC_SUBR=	mpd5
CONFSUF=	conf secret script
DOCSDIR=	${PREFIX}/share/doc/mpd5
PORTDOCS=	README mpd*
PLIST_FILES=	${CONFSUF:S/^/etc\/mpd5\/mpd./:S/$/.sample/} sbin/mpd5

.if !defined(WITHOUT_MAN)
PLIST_FILES+=	man/man8/mpd5.8.gz
.endif

.include <bsd.port.mk>
