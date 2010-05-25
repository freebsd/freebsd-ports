# New ports collection makefile for:	nfdump-devel
# Date created:				2007-05-20
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfdump-devel
PORTVERSION=	20070808
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nfdump/snapshot/nfdump-snapshot-${PORTVERSION}
DISTNAME=	nfdump-snapshot-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Development version of tools to collect and process NetFlow data

BUILD_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-nfprofile --with-rrdpath=${LOCALBASE}

#flow-tools support
OPTIONS=	FT2NFDUMP	"With Flow-tools to nfdump converter" off \
		SFLOW		"Build sflow collector daemon also" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif

#for compatibility
#
.ifndef(WITHOUT_NFDUMP14_SUPPORT)
CONFIGURE_ARGS+=	--enable-compat14
.endif

PLIST_FILES=	bin/nfcapd bin/nfdump bin/nfreplay bin/nfexpire bin/nfprofile
MAN1=		nfcapd.1 nfdump.1 nfexpire.1 nfprofile.1 nfreplay.1
PORTDOCS=	AUTHORS ChangeLog INSTALL README

#flow-tools support
.if defined(WITH_FT2NFDUMP)
BUILD_DEPENDS+=		flow-cat:${PORTSDIR}/net-mgmt/flow-tools
CONFIGURE_ARGS+=	--enable-ftconv --with-ftpath=${LOCALBASE}
PLIST_FILES+=	bin/ft2nfdump
MAN1+=		ft2nfdump.1
.endif

#sflow capture support
.if defined(WITH_SFLOW)
CONFIGURE_ARGS+=	--enable-sflow
PLIST_FILES+=	bin/sfcapd
MAN1+=		sfcapd.1
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
