# New ports collection makefile for:	samba-vscan
# Date created:		27 February 2004
# Whom:			Jean Milanez Melo <jmelo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	samba-vscan
PORTVERSION=	0.3.6c
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.openantivirus.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	On-access virus scanning with Samba

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/${VSCAN_SAMBA_PORT}:configure

OPTIONS=	VSCAN_ANTIVIR "for use with AntiVir" off \
		VSCAN_CLAMAV "for use with Clam AntiVirus Daemon" off \
		VSCAN_FPROTD "for use with F-Prot Daemon" off \
		VSCAN_FSAV "for use with F-Secure AntiVirus" off \
		VSCAN_ICAP "for use with an ICAP anti-virus" off \
		VSCAN_KAVP "for use with Kaspersky AntiVirus" off \
		VSCAN_MKSD "for use with mks32" off \
		VSCAN_NAI "for use with NAI/McAfee uvscan" off \
		VSCAN_OAV "for use with OpenAntiVirus.org ScannerDaemon" off \
		VSCAN_SOPHOS "for use with Sophos" off \
		VSCAN_TREND "for use with Trend Micro FileScanner" off

PORTDOCS=	AUTHORS COPYING ChangeLog FAQ INSTALL NEWS README

USE_AUTOTOOLS=	autoconf:262
VSCAN_SAMBA_PORT?=	samba3
SAMBA_WRKSRC!=	cd ${.CURDIR}/../../net/${VSCAN_SAMBA_PORT}; ${MAKE} -V WRKSRC
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-samba-source=${SAMBA_WRKSRC}
ETCDIR=		etc/samba-vscan
SUB_FILES=	pkg-message
VFSDIR?=	lib/samba/vfs
VSCAN_NAME=
VSCAN_CONF=
ALL_TARGET=

.include <bsd.port.pre.mk>

.if ${VSCAN_SAMBA_PORT} != "samba3"
VFSDIR=lib/samba
.endif

.if defined(WITH_VSCAN_ANTIVIR)
ALL_TARGET+=antivir
VSCAN_NAME+=vscan-antivir.so
VSCAN_CONF+=antivir/vscan-antivir.conf
.endif

.if defined(WITH_VSCAN_CLAMAV)
ALL_TARGET+=clamav
VSCAN_NAME+=vscan-clamav.so
VSCAN_CONF+=clamav/vscan-clamav.conf
.endif

.if defined(WITH_VSCAN_FPROTD)
ALL_TARGET+=fprotd
VSCAN_NAME+=vscan-fprotd.so
VSCAN_CONF+=fprot/vscan-fprotd.conf
.endif

.if defined(WITH_VSCAN_FSAV)
ALL_TARGET+=fsav
VSCAN_NAME+=vscan-fsav.so
VSCAN_CONF+=f-secure/vscan-fsav.conf
.endif

.if defined(WITH_VSCAN_ICAP)
ALL_TARGET+=icap
VSCAN_NAME+=vscan-icap.so
VSCAN_CONF+=icap/vscan-icap.conf
.endif

.if defined(WITH_VSCAN_KAVP)
ALL_TARGET+=kavp
VSCAN_NAME+=vscan-kavp.so
VSCAN_CONF+=kaspersky/vscan-kavp.conf
.endif

.if defined(WITH_VSCAN_MKSD)
ALL_TARGET+=mksd
VSCAN_NAME+=vscan-mksd.so
VSCAN_CONF+=mks/vscan-mks32.conf
.endif

.if defined(WITH_VSCAN_NAI)
ALL_TARGET+=nai
VSCAN_NAME+=vscan-mcdaemon.so
VSCAN_CONF+=nai/vscan-mcdaemon.conf
.endif

.if defined(WITH_VSCAN_OAV)
ALL_TARGET+=oav
VSCAN_NAME+=vscan-oav.so
VSCAN_CONF+=openantivirus/vscan-oav.conf
.endif

.if defined(WITH_VSCAN_SOPHOS)
ALL_TARGET+=sophos
VSCAN_NAME+=vscan-sophos.so
VSCAN_CONF+=sophos/vscan-sophos.conf
.endif

.if defined(WITH_VSCAN_TREND)
ALL_TARGET+=trend
VSCAN_NAME+=vscan-trend.so
VSCAN_CONF+=trend/vscan-trend.conf
.endif

PLIST_FILES+=	${VSCAN_NAME:S|^|${VFSDIR}/|} \
		${VSCAN_CONF:S|^|${ETCDIR}/|:C|(.*/).*/(.*.conf)|\1\2|}
PLIST_DIRS=	${ETCDIR} ${VFSDIR}

pre-configure:
.if ${VSCAN_SAMBA_PORT} == "samba3"
		@cd ${SAMBA_WRKSRC}; make proto 2>&1 > /dev/null
.endif

do-install:
.for i in ${VSCAN_NAME}
	@${MKDIR} ${PREFIX}/${VFSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/${VFSDIR}
.endfor
	@${MKDIR} ${PREFIX}/${ETCDIR}
.for i in ${VSCAN_CONF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${ETCDIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
