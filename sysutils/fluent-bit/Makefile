PORTNAME=	fluent-bit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
CATEGORIES=	sysutils

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Fast and lightweight data forwarder
WWW=		https://fluentbit.io/

LICENSE=	APACHE20

BROKEN_mips=		fails to build: conflicting types for 'restrict'
BROKEN_mips64=		fails to build: conflicting types for 'restrict'

USE_GITHUB=	yes
GH_ACCOUNT=	fluent

USES=		bison cmake:noninja compiler:c11 gmake localbase:ldflags

OPTIONS_DEFINE=		SSL PGSQL
OPTIONS_DEFAULT=	SSL

LIB_DEPENDS=		libyaml.so:textproc/libyaml
LDFLAGS+=		-lexecinfo
CMAKE_ARGS=		-DFLB_DEBUG=Off -DFLB_TRACE=Off -DFLB_LUAJIT=Off

SSL_USES=		ssl
SSL_CMAKE_ON=		-DFLB_TLS=On
SSL_CMAKE_OFF=		-DFLB_TLS=Off

EXAMPLES_CMAKE_ON=	-DFLB_EXAMPLES=On
EXAMPLES_CMAKE_OFF=	-DFLB_EXAMPLES=Off

PGSQL_USES=		pgsql
PGSQL_CMAKE_ON=		-DFLB_OUT_PGSQL=On
PGSQL_CMAKE_OFF=	-DFLB_OUT_PGSQL=Off

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/parsers.conf ${STAGEDIR}${ETCDIR}/parsers.conf.sample

.include <bsd.port.mk>
