# Created by: Archie Cobbs
# $FreeBSD$

PORTNAME=	mpd
DISTVERSION=	5.7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Mpd5/Mpd-${PORTVERSION}
DIST_SUBDIR=	mpd5
PKGNAMESUFFIX=	5

MAINTAINER=	mav@FreeBSD.org
COMMENT=	Multi-link PPP daemon based on netgraph(4)

OPTIONS_DEFINE=	NG_IPACCT
NG_IPACCT_DESC=	Use ng_ipacct kernel module from port

HAS_CONFIGURE=	YES
CONFIGURE_WRKSRC=	"${WRKSRC}/src"

USE_OPENSSL=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNG_IPACCT}
BUILD_DEPENDS+=	${LOCALBASE}/include/netgraph/ng_ipacct.h:${PORTSDIR}/net-mgmt/ng_ipacct
.if exists(${KMODDIR}/ng_ipacct.ko)
RUN_DEPENDS+=	${KMODDIR}/ng_ipacct.ko:${PORTSDIR}/net-mgmt/ng_ipacct
.else
RUN_DEPENDS+=	/boot/modules/ng_ipacct.ko:${PORTSDIR}/net-mgmt/ng_ipacct
.endif
.endif

MAN8=		mpd5.8
MANCOMPRESSED=	maybe
USE_RC_SUBR=	mpd5
HTMLNUM!=	jot 70 1
CONFSUF=	conf secret script
DOCSDIR=	${PREFIX}/share/doc/mpd5
PORTDOCS=	${HTMLNUM:S/^/mpd/:S/$/.html/} mpd.html mpd.ps README	\
		mpd_toc.html
PLIST_DIRS=	etc/mpd5
PLIST_FILES=	${CONFSUF:S/^/etc\/mpd5\/mpd./:S/$/.sample/} sbin/mpd5

.include <bsd.port.mk>
