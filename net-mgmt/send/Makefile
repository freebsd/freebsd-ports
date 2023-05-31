PORTNAME=	send
PORTVERSION=	0.3
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	net-mgmt

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Secure Neighbor Discovery implementation for IPv6

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Implementation is based on older obsolete RFC
EXPIRATION_DATE=	2023-06-03

LIB_DEPENDS=	libdnet.so:net/libdnet

USES=		gmake ncurses readline ssl
BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	error: unknown type name 'IPAddressRange'
USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd
USE_RC_SUBR=	sendd

SUB_FILES=	pkg-message
PORTDOCS=	README UserGuide.pdf
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
