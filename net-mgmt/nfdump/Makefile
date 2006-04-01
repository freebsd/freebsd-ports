# New ports collection makefile for:	nfdump
# Date created:				2004-09-29
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfdump
PORTVERSION=	1.5
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Command-line tools to collect and process NetFlow data

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
#for compatibility
#
.ifndef(WITHOUT_NFDUMP14_SUPPORT)
CONFIGURE_ARGS=		--enable-compat14
.endif
#flow-tools support
OPTIONS=	FT2NFDUMP	"With Flow-tools to nfdump converter" off

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/nfcapd bin/nfdump bin/nfprofile bin/nfreplay bin/nfclean.pl
MAN1=		nfcapd.1 nfdump.1 nfprofile.1 nfreplay.1
PORTDOCS=	AUTHORS ChangeLog INSTALL README

#flow-tools support
.if defined(WITH_FT2NFDUMP)
BUILD_DEPENDS+=		flow-cat:${PORTSDIR}/net-mgmt/flow-tools
CONFIGURE_ARGS+=	--enable-ftconv --with-ftpath=${LOCALBASE}
PLIST_FILES+=	bin/ft2nfdump
MAN1+=		ft2nfdump.1
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
