# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	h2o
PORTVERSION=	1.2.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Optimized HTTP2 server with support for HTTP/1.x

LICENSE=	MIT

USE_GITHUB=	yes

USES=		cmake compiler:c11 shebangfix
SHEBANG_FILES=	share/h2o/start_server

PORTDOCS=	README.md

SUB_FILES=	${PORTNAME}
SUB_LIST+=	H2O_USER=${H2O_USER} \
		H2O_GROUP=${H2O_GROUP} \
		H2O_PIDDIR=${H2O_PIDDIR} \
		H2O_LOGDIR=${H2O_LOGDIR}

PLIST_SUB=	H2O_USER=${H2O_USER} \
		H2O_GROUP=${H2O_GROUP} \
		H2O_PIDDIR=${H2O_PIDDIR} \
		H2O_LOGDIR=${H2O_LOGDIR}

H2O_USER?=	www
H2O_GROUP?=	www

H2O_LOGDIR=	/var/log/${PORTNAME}/
H2O_PIDDIR=	/var/run/${PORTNAME}/

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900000
BROKEN=		fails to compile on 8.x
.endif

CMAKE_ARGS+=	-DWITH_BUNDLED_SSL=OFF
USE_OPENSSL_PORT=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${H2O_PIDDIR} \
		${STAGEDIR}${H2O_LOGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${FILESDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

.include <bsd.port.mk>
