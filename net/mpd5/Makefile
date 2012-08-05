# New ports collection makefile for:	mpd
# Date created:				20 Sep 2005
# Whom:					Archie Cobbs
#
# $FreeBSD$
#

PORTNAME=	mpd
DISTVERSION=	5.6
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Mpd5/Mpd-${PORTVERSION}
DIST_SUBDIR=	mpd5

MAINTAINER=	mav@FreeBSD.org
COMMENT=	Multi-link PPP daemon based on netgraph(4)

LATEST_LINK=	mpd5

OPTIONS=	NG_CAR "Use ng_car kernel module from port (< 7.0 only)" off\
		NG_IPACCT "Use ng_ipacct kernel module from port" off

HAS_CONFIGURE=	YES
CONFIGURE_WRKSRC=	"${WRKSRC}/src"

USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700041 && defined(WITH_NG_CAR)
BUILD_DEPENDS+=	${LOCALBASE}/include/netgraph/ng_car.h:${PORTSDIR}/net/ng_car
.if exists(${KMODDIR}/ng_car.ko)
RUN_DEPENDS+=	${KMODDIR}/ng_car.ko:${PORTSDIR}/net/ng_car
.else
RUN_DEPENDS+=	/boot/modules/ng_car.ko:${PORTSDIR}/net/ng_car
.endif
.endif

.if defined(WITH_NG_IPACCT)
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

.include <bsd.port.post.mk>
