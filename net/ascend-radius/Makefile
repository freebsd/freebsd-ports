# New ports collection makefile for:	ascend-radius
# Date created:				August 28th 96
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ascend-radius
PORTVERSION=	980618
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ascend.com/pub/Software-Releases/Radius/Current/ \
		ftp://ftp.ascend.com/pub/Software-Releases/Radius/Current/doc/ \
		ftp://ftp.ascend.com/pub/Software-Releases/Radius/Archive/ \
		ftp://ftp.ascend.com/pub/Software-Releases/Radius/Archive/doc/
DISTFILES=	radius-980618.tar.gz \
		radius.ps \
		radius.pdf \
		980618.ps \
		980618.pdf
EXTRACT_ONLY=	radius-980618.tar.gz

MAINTAINER=	ports@FreeBSD.org

WRKPREFIX=	radius-980618/radius-1.16-ascend
WRKSRC=		${WRKDIR}/${WRKPREFIX}/ascendd

ALL_TARGET=	all dbm
MAN1=		builddbm.1 users-file-syntax.1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/radiusd ${PREFIX}/sbin
		${INSTALL_PROGRAM} ${WRKSRC}/radiusd.dbm ${PREFIX}/sbin
		${INSTALL_PROGRAM} ${WRKSRC}/builddbm ${PREFIX}/sbin
		${INSTALL_MAN} ${WRKDIR}/${WRKPREFIX}/man1/users-file-syntax.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKDIR}/${WRKPREFIX}/man1/builddbm.1 ${PREFIX}/man/man1
.ifndef NOPORTDOCS
		@ ${MKDIR} ${PREFIX}/share/doc/ascend-radius
		for file in ascend.doc draft-ietf-radius-accounting-01.txt draft-ietf-radius-radius-03.txt draft-ietf-radius-radius-04.txt; do \
			${INSTALL_DATA} ${WRKDIR}/${WRKPREFIX}/doc/$$file ${PREFIX}/share/doc/ascend-radius; \
		done
		for file in ChangeLog README README.cexample README.dict; do \
			${INSTALL_DATA} ${WRKDIR}/${WRKPREFIX}/$$file ${PREFIX}/share/doc/ascend-radius; \
		done
		${INSTALL_DATA} ${DISTDIR}/radius.ps ${PREFIX}/share/doc/ascend-radius
		${INSTALL_DATA} ${DISTDIR}/radius.pdf ${PREFIX}/share/doc/ascend-radius
		${INSTALL_DATA} ${DISTDIR}/980618.ps ${PREFIX}/share/doc/ascend-radius
		${INSTALL_DATA} ${DISTDIR}/980618.pdf ${PREFIX}/share/doc/ascend-radius
.endif
		@ ${MKDIR} ${PREFIX}/etc/raddb
		@ ${CHOWN} root.wheel ${PREFIX}/etc/raddb
		@ ${CHMOD} 700 ${PREFIX}/etc/raddb
		for file in clients.example dictionary users.example; do \
			${INSTALL} -c -o root -g wheel -m 0400 ${WRKDIR}/${WRKPREFIX}/raddb/$$file ${PREFIX}/etc/raddb; \
		done
		@ ${MKDIR} /var/log/radacct
		@ ${CHOWN} root.wheel /var/log/radacct
		@ ${CHMOD} 700 /var/log/radacct

.include <bsd.port.mk>
