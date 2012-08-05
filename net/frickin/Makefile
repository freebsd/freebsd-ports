# New ports collection makefile for:	frickin
# Date created:				2 December 2006
# Whom:					Alex Miller <asm@asm.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	frickin
DISTVERSION=	2.0BETA2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	asm@asm.kiev.ua
COMMENT=	Frickin PPTP Proxy

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_RC_SUBR=	frickin
SUB_FILES=	pkg-message
PORTDOCS=	INSTALL LICENSE
PLIST_FILES=	sbin/frickin2 etc/frickin.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g;' \
	${WRKSRC}/src/Makefile.FreeBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}2 ${PREFIX}/sbin/${PORTNAME}2
	${INSTALL_DATA} ${WRKSRC}/frickin.conf.default ${PREFIX}/etc/frickin.conf.sample

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}

.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
