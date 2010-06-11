# New ports collection makefile for:	nfdump
# Date created:				2004-09-29
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfdump
PORTVERSION=	1.6.1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Command-line tools to collect and process NetFlow data

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

#flow-tools support
OPTIONS=	FT2NFDUMP	"With Flow-tools to nfdump converter" off \
		NFPROFILE	"With nfprofile  (nfsen requires it)" on \
		SFLOW		"Build sflow collector daemon also" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif

#for compatibility
#
.ifndef(WITHOUT_NFDUMP15_SUPPORT)
CONFIGURE_ARGS=		--enable-compat15
.endif

PLIST_FILES=	bin/nfcapd bin/nfdump bin/nfreplay bin/nfexpire
MAN1=		nfcapd.1 nfdump.1 nfreplay.1 nfexpire.1
MAN1+=		nfprofile.1 ft2nfdump.1 sfcapd.1
PORTDOCS=	AUTHORS ChangeLog INSTALL README

.if defined(WITH_NFPROFILE)
CONFIGURE_ARGS+=	--enable-nfprofile --with-rrdpath=${LOCALBASE}
PLIST_FILES+=	bin/nfprofile
#MAN1+=		nfprofile.1
BUILD_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif

#flow-tools support
.if defined(WITH_FT2NFDUMP)
BUILD_DEPENDS+=		flow-cat:${PORTSDIR}/net-mgmt/flow-tools
CONFIGURE_ARGS+=	--enable-ftconv --with-ftpath=${LOCALBASE}
PLIST_FILES+=	bin/ft2nfdump
#MAN1+=		ft2nfdump.1
.endif

#sflow capture support
.if defined(WITH_SFLOW)
CONFIGURE_ARGS+=	--enable-sflow
PLIST_FILES+=	bin/sfcapd
#MAN1+=		sfcapd.1
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
