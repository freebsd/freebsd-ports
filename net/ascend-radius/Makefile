# New ports collection makefile for:	ascend-radius
# Version required:			961015 (v1.16)
# Date created:				August 28th 96
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1996/10/18 11:50:13 jfitz Exp $
#

DISTNAME=	radius-961015
PKGNAME=	ascend-radius-961015
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ascend.com/pub/Software-Releases/Radius/Current/ \
		ftp://ftp.ascend.com/pub/Software-Releases/Radius/Archive/

MAINTAINER=	jfitz@FreeBSD.ORG

WRKPREFIX=	radius-961015/radius-1.16-ascend
WRKSRC=		${WRKDIR}/${WRKPREFIX}/ascendd

ALL_TARGET=	all dbm

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/radiusd ${PREFIX}/sbin
		${INSTALL_PROGRAM} ${WRKSRC}/radiusd.dbm ${PREFIX}/sbin
		${INSTALL_PROGRAM} ${WRKSRC}/builddbm ${PREFIX}/sbin
.ifdef NOMANCOMPRESS
		${INSTALL_MAN} ${WRKDIR}/${WRKPREFIX}/man1/users-file-syntax.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKDIR}/${WRKPREFIX}/man1/builddbm.1 ${PREFIX}/man/man1
.else
		@ ${CP} ${WRKDIR}/${WRKPREFIX}/man1/users-file-syntax.1 ${WRKSRC}
		@ ${CP} ${WRKDIR}/${WRKPREFIX}/man1/builddbm.1 ${WRKSRC}
		@ gzip -9nf ${WRKSRC}/users-file-syntax.1
		@ gzip -9nf ${WRKSRC}/builddbm.1
		${INSTALL_MAN} ${WRKSRC}/users-file-syntax.1.gz ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/builddbm.1.gz ${PREFIX}/man/man1
.endif
.ifndef NOPORTDOCS
		@ mkdir -p ${PREFIX}/share/doc/ascend-radius
		for file in ascend.doc draft-ietf-radius-accounting-01.txt draft-ietf-radius-radius-03.txt draft-ietf-radius-radius-04.txt; do \
			${INSTALL_DATA} ${WRKDIR}/${WRKPREFIX}/doc/$$file ${PREFIX}/share/doc/ascend-radius; \
		done
		for file in ChangeLog README README.cexample README.dict; do \
			${INSTALL_DATA} ${WRKDIR}/${WRKPREFIX}/$$file ${PREFIX}/share/doc/ascend-radius; \
		done
.endif
		@ mkdir -p ${PREFIX}/etc/raddb
		@ chown root.wheel ${PREFIX}/etc/raddb
		@ chmod 700 ${PREFIX}/etc/raddb
		for file in clients.example dictionary users.example; do \
			${INSTALL} -c -o root -g wheel -m 0400 ${WRKDIR}/${WRKPREFIX}/raddb/$$file ${PREFIX}/etc/raddb; \
		done
		@ mkdir -p /var/log/radacct
		@ chown root.wheel /var/log/radacct
		@ chmod 700 /var/log/radacct

.include <bsd.port.mk>
