# ex:ts=8
# Ports collection makefile for:  cdpr
# Date created:                          Tue Jul 08, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	cdpr
PORTVERSION=	2.2.1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Cisco Discovery Protocol Reporter

LDFLAGS+=	-L${LOCALBASE}/lib -lpcap

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} ${PORTNAME}.c cdprs.c conffile.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cdprs/* ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cdpr.conf ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/README.cdprs ${DOCSDIR}/README.cdprs
.endif

.include <bsd.port.mk>
