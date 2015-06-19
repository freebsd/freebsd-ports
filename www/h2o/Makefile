# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	h2o
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Optimized HTTP2 server with support for HTTP/1.x

LICENSE=	MIT

LIB_DEPENDS=	libyaml.so:${PORTSDIR}/textproc/libyaml

USE_GITHUB=	yes
GH_ACCOUNT=	h2o
GH_TAGNAME=	v1.0.1
GH_COMMIT=	c28f39e

MAKE_JOBS_UNSAFE=	yes
USES=	cmake:outsource compiler:c11

USE_OPENSSL=	yes

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

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${H2O_PIDDIR} \
		${STAGEDIR}${H2O_LOGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${FILESDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${INSTALL_PROGRAM} ${WRKDIR}/.build/h2o ${STAGEDIR}${PREFIX}/bin/h2o

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BROKEN=	fails to compile on 8.x
.endif

.include <bsd.port.post.mk>
