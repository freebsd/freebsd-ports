# Created by: matthew@FreeBSD.org
# $FreeBSD$

PORTNAME=	logstash-contrib
DISTVERSION=	1.4.2
CATEGORIES=	sysutils
PORTREVISION=	2

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Standard plugins contributed to the Logstash project

RUN_DEPENDS=	${LOCALBASE}/logstash/bin/logstash:${PORTSDIR}/sysutils/logstash

USE_GITHUB=	yes
GH_ACCOUNT=	elasticsearch
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	efd53ef

NO_BUILD=	yes
NO_ARCH=	yes

LOGSTASH_LIB_SUBDIR=	lib/logstash
LOGSTASH_LIB=		${LOCALBASE}/logstash/${LOGSTASH_LIB_SUBDIR}

do-install::
	@${MKDIR} ${STAGEDIR}${LOGSTASH_LIB}/
	cd ${WRKSRC}/${LOGSTASH_LIB_SUBDIR} && \
	    ${COPYTREE_BIN} . ${STAGEDIR}${LOGSTASH_LIB} \
		"! -name version.rb ! -name zeromq.rb"

.include <bsd.port.mk>
