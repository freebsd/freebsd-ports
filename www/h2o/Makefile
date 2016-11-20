# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	h2o
PORTVERSION=	2.0.4
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Optimized HTTP2 server with support for HTTP/1.x

LICENSE=	MIT

USE_GITHUB=	yes

USES=		cmake compiler:c11 perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	share/h2o/start_server

PORTDOCS=	README.md

SUB_FILES=	${PORTNAME}
SUB_LIST+=	H2O_USER=${H2O_USER} \
		H2O_GROUP=${H2O_GROUP} \
		H2O_LOGDIR=${H2O_LOGDIR}

PLIST_SUB=	H2O_USER=${H2O_USER} \
		H2O_GROUP=${H2O_GROUP} \
		H2O_LOGDIR=${H2O_LOGDIR}

H2O_USER?=	www
H2O_GROUP?=	www

H2O_LOGDIR=	/var/log/${PORTNAME}/

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	LIBRESSL
LIBRESSL_DESC=	Build with bundled LibreSSL instead of OpenSSL
OPTIONS_DEFAULT=	LIBRESSL

CMAKE_ARGS+=	-DEXTRA_LIBRARIES=OFF -DWITHOUT_LIBS=ON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBRESSL}
CMAKE_ARGS+=	-DWITH_BUNDLED_SSL=ON
WITH_OPENSSL_PORT=	no
.else
CMAKE_ARGS+=	-DWITH_BUNDLED_SSL=OFF
WITH_OPENSSL_PORT=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|exec perl|exec ${LOCALBASE}/bin/perl|' \
			${WRKSRC}/share/h2o/annotate-backtrace-symbols \
			${WRKSRC}/share/h2o/fetch-ocsp-response \
			${WRKSRC}/share/h2o/kill-on-close \
			${WRKSRC}/share/h2o/start_server

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${H2O_LOGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${FILESDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

.include <bsd.port.mk>
