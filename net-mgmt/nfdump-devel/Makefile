# New ports collection makefile for:	nfdump
# Date created:				2004-09-29
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfdump
PORTVERSION=	1.3
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Command-line tools to collect and process NetFlow data

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/nfcapd bin/nfdump bin/nfprofile bin/nfreplay bin/nfclean.pl
MAN1=		nfcapd.1 nfdump.1 nfprofile.1 nfreplay.1
PORTDOCS=	AUTHORS ChangeLog INSTALL README

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
