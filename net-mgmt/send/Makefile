# Created by: Janos Mohacsi <mohacsi@niif.hu>
# $FreeBSD$

PORTNAME=	send
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	LOCAL/hrs
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Secure Neighbor Discovery implementation for IPv6

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdnet.so:net/libdnet

USES=		gmake readline ssl
USE_RC_SUBR=	sendd
SUB_FILES=	pkg-message
PORTDOCS=	README UserGuide.pdf
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

post-extract:
	${INSTALL_DATA} ${WRKSRC}/examples/ipext/ipext_verify.conf \
	    ${WRKSRC}/examples/ipext/ca/ipext.conf \
	    ${WRKSRC}/examples/
	${INSTALL_DATA} ${WRKSRC}/docs/UserGuide.pdf \
	    ${WRKSRC}/UserGuide.pdf

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/sendd
	for F in sendd.conf params.conf ipext.conf ipext_verify.conf; do \
		${INSTALL_DATA} ${WRKSRC}/examples/$$F \
		    ${STAGEDIR}${PREFIX}/etc/sendd/$${F}-dist; \
	done

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
