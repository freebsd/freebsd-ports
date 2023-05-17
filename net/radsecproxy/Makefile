PORTNAME=	radsecproxy
DISTVERSION=	1.9.2
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generic RADIUS proxy
WWW=		https://radsecproxy.github.io

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnettle.so:security/nettle

USES=		compiler:c11 cpe localbase:ldflags ssl
CPE_VENDOR=	uninett
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=strict-prototypes
.endif

post-install:
	${MAKE} install-man -C ${WRKSRC} ${MAKE_ARGS}
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.post.mk>
