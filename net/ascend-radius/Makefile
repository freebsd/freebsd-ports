# New ports collection makefile for:	ascend-radius
# Version required:			970424 (v1.16)
# Date created:				August 28th 96
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.8 1997/01/24 12:10:10 asami Exp $
#

#DISTNAME=	radius-970424
PKGNAME=	ascend-radius-970424
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ascend.com/pub/Software-Releases/Radius/Current/ \
		ftp://ftp.ascend.com/pub/Software-Releases/Radius/Current/doc/ \
		ftp://ftp.ascend.com/pub/Software-Releases/Radius/Archive/ \
		ftp://ftp.ascend.com/pub/Software-Releases/Radius/Archive/doc/
DISTFILES=	radius-970424.tar.gz \
		radius.ps \
		radius.pdf \
		rradius.ps \
		rradius.pdf
EXTRACT_ONLY=	radius-970424.tar.gz

MAINTAINER=	jfitz@FreeBSD.ORG

WRKPREFIX=	radius-970424/radius-ascend/radius-1.16-ascend
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
		${INSTALL_DATA} ${DISTDIR}/rradius.ps ${PREFIX}/share/doc/ascend-radius
		${INSTALL_DATA} ${DISTDIR}/rradius.pdf ${PREFIX}/share/doc/ascend-radius
.endif
		@ ${MKDIR} ${PREFIX}/etc/raddb
		@ chown root.wheel ${PREFIX}/etc/raddb
		@ chmod 700 ${PREFIX}/etc/raddb
		for file in clients.example dictionary users.example; do \
			${INSTALL} -c -o root -g wheel -m 0400 ${WRKDIR}/${WRKPREFIX}/raddb/$$file ${PREFIX}/etc/raddb; \
		done
		@ ${MKDIR} /var/log/radacct
		@ chown root.wheel /var/log/radacct
		@ chmod 700 /var/log/radacct

.include <bsd.port.mk>
