# Created by: Janos Mohacsi <mohacsi@niif.hu>
# $FreeBSD$

PORTNAME=	send
PORTVERSION=	0.3
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	anchie
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	anchie@FreeBSD.org
COMMENT=	Secure Neighbor Discovery implementation for IPv6

BROKEN=		Fails to link

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

USE_GMAKE=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDOCS=	README UserGuide.pdf

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900042
IGNORE=		is supported only on 9.0 and later
.endif

post-install:
	${MKDIR} ${PREFIX}/etc/sendd/
	${INSTALL_DATA} ${WRKSRC}/examples/ipext/ipext_verify.conf \
		${WRKSRC}/examples/ipext/ca/ipext.conf \
		${WRKSRC}/examples/
	${INSTALL_DATA} ${WRKSRC}/docs/UserGuide.pdf \
		${WRKSRC}/UserGuide.pdf
	for F in sendd.conf params.conf ipext.conf ipext_verify.conf; do \
		${INSTALL_DATA} ${WRKSRC}/examples/$$F \
		${PREFIX}/etc/sendd/$${F}-dist; \
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
