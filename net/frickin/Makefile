# New ports collection makefile for:	frickin
# Date created:				2 December 2006
# Whom:					Alex Miller <asm@asm.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	frickin
DISTVERSION=	2.0BETA1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	frickin

MAINTAINER=	asm@asm.kiev.ua
COMMENT=	Frickin PPTP Proxy

USE_RC_SUBR=	frickin.sh
SUB_FILES=	pkg-message
PORTDOCS=	INSTALL HISTORY
PLIST_FILES=	sbin/frickin2 etc/frickin.conf.sample
PKGMESSAGE=	${WRKDIR}/pkg-messag

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}2 ${PREFIX}/sbin/${PORTNAME}2
	${INSTALL_DATA} ${WRKSRC}/frickin.conf ${PREFIX}/etc/frickin.conf.sample

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}

.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		FreeBSD 4.xx does not have pf support
.elif ${OSVERSION} < 600000
IGNORE=		Does not compile with old version of pf
.endif

.include <bsd.port.post.mk>
