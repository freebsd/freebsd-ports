# New ports collection makefile for:	ab25
# Date created:		July 2 2011
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	ab25
PORTVERSION=	0.2.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Utility for ARIB STD-B25 ECM handling in MPEG2-TS stream

LIB_DEPENDS=	pcsclite:${PORTSDIR}/devel/pcsc-lite
RUN_DEPENDS=	${LOCALBASE}/lib/pcsc/drivers/ifd-ccid.bundle/Contents/FreeBSD/libccid.so:${PORTSDIR}/devel/libccid

USE_LDCONFIG=	yes
PORTDOCS=	readme.txt

PLIST_FILES=	bin/b25 \
		lib/libab25.a lib/libab25_p.a lib/libab25.so.1 lib/libab25.so \
		include/ab25/arib_std_b25.h include/ab25/b_cas_card.h
PLIST_DIRS=	include/ab25

pre-su-install:
	${MKDIR} ${PREFIX}/include/ab25

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
