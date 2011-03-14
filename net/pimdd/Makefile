# New ports collection makefile for:	pimdd
# Date created:		18 March 2004
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pimdd
PORTVERSION=	0.2.1.0
CATEGORIES=	net
MASTER_SITES=	http://www.antc.uoregon.edu/PIMDM/
DISTNAME=	pimd-dense

MAINTAINER=	ports@FreeBSD.org
COMMENT=	\
	UO Dense Protocol-Independent Multicast (PIM-DM) daemon for IPv4

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_MAN=		defined
PIMDD_DOCS=	pimd-dense.html README CHANGES RELEASE.NOTES

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800070
BROKEN=		does not compile: error: IGMP_HOST_MEMBERSHIP_REPORT undeclared
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/etc/pimd.conf|${PREFIX}/etc/pimd.conf|g' ${WRKSRC}/pathnames.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pimdd ${PREFIX}/sbin/pimdd
	${INSTALL_DATA} ${WRKSRC}/pimdd.conf ${PREFIX}/etc/pimdd.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PIMDD_DOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.post.mk>
