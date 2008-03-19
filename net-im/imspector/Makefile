# New ports collection makefile for:   	imspector
# Date created:        			17 March 2008
# Whom:            			Ilja Dejs <ilja.dejs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	imspector
PORTVERSION=	0.5
CATEGORIES=	net-im
MASTER_SITES=	http://www.imspector.org/downloads/

MAINTAINER=	lawrence@aslak.net
COMMENT=	IM transparent proxy with monitoring, blocking, and content-filtering supports

CFLAGS+=	-fPIC

CONFIG_FILES=	imspector.conf badwords.txt acl.txt

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.pre.mk>

MAKE_ENV+=	ETCDIR=${ETCDIR}

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/imspector.conf \
		${WRKSRC}/main.cpp
post-install:
.for f in ${CONFIG_FILES}
	@if [ ! -f ${ETCDIR}/${f} ]; then \
		${CP} -p ${ETCDIR}/${f}.sample ${ETCDIR}/${f} ; \
	fi
.endfor

.include <bsd.port.post.mk>
