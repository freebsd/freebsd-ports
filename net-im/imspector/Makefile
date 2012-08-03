# New ports collection makefile for:   	imspector
# Date created:        			17 March 2008
# Whom:            			Ilja Dejs <ilja.dejs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	imspector
PORTVERSION=	20111108
CATEGORIES=	net-im
MASTER_SITES=	http://www.imspector.org/downloads/ \
		http://tsatsenko.ru/ports/distfiles/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	IM transparent proxy with monitoring, blocking, and content-filtering

LICENSE=	GPLv2

CFLAGS+=	-fPIC -I ${LOCALBASE}/include -DHAVE_SSL
USE_GMAKE=	YES
USE_ICONV=	YES
USE_OPENSSL=	YES
USE_LDCONFIG=	${LOCALBASE}/lib/imspector

CONFIG_FILES=	imspector.conf badwords.txt acl.txt

USE_RC_SUBR=	${PORTNAME}

MAKE_ENV+=	ETCDIR=${ETCDIR}

post-extract:
	${MV}	${WRKDIR}/${PORTNAME} ${WRKSRC}
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

.include <bsd.port.mk>
