# ex:ts=8
# Ports collection makefile for:  cdpr
# Date created:                          Tue Jul 08, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	cdpr
PORTVERSION=	1.0.8
CATEGORIES=	net
MASTER_SITES=	http://freebsdcluster.org/~mich/software/ \
		http://www.monkeymental.com/mmfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Cisco Discovery Protocol Reporter

CFLAGS+=	-ggdb
LDFLAGS+=	-L${LOCALBASE}/lib -lpcap

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
