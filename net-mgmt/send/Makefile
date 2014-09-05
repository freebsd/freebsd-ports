# Created by: Janos Mohacsi <mohacsi@niif.hu>
# $FreeBSD$

PORTNAME=	send
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Secure Neighbor Discovery implementation for IPv6

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdnet.so:${PORTSDIR}/net/libdnet

USES=		gmake readline
USE_RC_SUBR=	sendd
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDOCS=	README UserGuide.pdf
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900042
IGNORE=		is supported only on 9.0 and later
.endif

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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
