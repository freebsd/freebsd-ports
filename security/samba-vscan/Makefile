# New ports collection makefile for:	samba-vscan
# Date created:		27 February 2004
# Whom:			Jean Milanez Melo <jmelo@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	samba-vscan
PORTVERSION=	0.3.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	openantivirus

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	On-access virus scanning with Samba

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/${VSCAN_SAMBA_PORT}:configure
.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING ChangeLog FAQ INSTALL NEWS README
.endif

USE_BZIP2=	yes
SAMBA_WRKSRC=	`cd ${PORTSDIR}/net/${VSCAN_SAMBA_PORT}; make -V WRKSRC`
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-samba-source=${SAMBA_WRKSRC}
ETCDIR=		${PREFIX}/etc/samba-vscan
PKGMESSAGE=	${WRKDIR}/pkg-message
VSCAN_SAMBA_PORT?=samba3

.if ${VSCAN_SAMBA_PORT} == "samba3"
PLIST_SUB=	VFSDIR=lib/samba/vfs
.else
PLIST_SUB=	VFSDIR=lib/samba
.endif

pre-configure:
.if ${VSCAN_SAMBA_PORT} == "samba3"
		@cd ${SAMBA_WRKSRC}; make proto 2>&1 > /dev/null
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${PREFIX}/etc/samba-vscan
	@${INSTALL_DATA} ${WRKSRC}/clamav/vscan-clamav.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/fprot/vscan-fprotd.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/icap/vscan-icap.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/kaspersky/vscan-kavp.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/mks/vscan-mks32.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/openantivirus/vscan-oav.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/sophos/vscan-sophos.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/trend/vscan-trend.conf ${ETCDIR}
	@${SED} "s|%%PREFIX%%|${PREFIX}|g;" ${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
