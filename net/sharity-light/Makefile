# New ports collection makefile for:	sharity-light
# Date created:		14 June 1997
# Whom:			Dmitrij Tejblum <dima@tejblum.dnttm.rssi.ru>
#
# $FreeBSD$
#

PORTNAME=	sharity-light
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.obdev.at/ftp/pub/Products/Sharity-Light/
DISTNAME=	Sharity-Light.1.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An userland smbfs --- SMB to NFS protocols converter

MAN8=		smbmount.8

PLIST_FILES=	sbin/shlight sbin/unshlight
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800100
BROKEN=		does not compile
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/unshlight
	@${CP} ${FILESDIR}/unshlight.c ${WRKDIR}/unshlight
	@${CP} ${FILESDIR}/Makefile.unshlight ${WRKDIR}/unshlight/Makefile

post-build:
	cd ${WRKDIR}/unshlight && make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shlight ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKDIR}/unshlight/unshlight ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/FAQ.txt ${DOCSDIR}/FAQ
.endif
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
