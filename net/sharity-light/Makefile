# New ports collection makefile for:	sharity-light
# Date created:		14 June 1997
# Whom:			Dmitrij Tejblum <dima@tejblum.dnttm.rssi.ru>
#
# $FreeBSD$
#

PORTNAME=	sharity-light
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.obdev.at/pub/Products/Sharity-Light/	\
		ftp://ftp.warpnet.ro/mirrors/ftp.obdev.at/pub/Products/Sharity-Light/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dt
DISTNAME=	Sharity-Light.1.2

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An userland smbfs --- SMB to NFS protocols converter

MAN8=		smbmount.8

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
	${MKDIR} ${PREFIX}/share/doc/Sharity-Light
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/Sharity-Light/README
	${INSTALL_DATA} ${WRKSRC}/FAQ.txt ${PREFIX}/share/doc/Sharity-Light/FAQ
.endif
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
