# Created by: Ilja Dejs <ilja.dejs@gmail.com>
# $FreeBSD$

PORTNAME=	imspector
PORTVERSION=	20111108
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://tsatsenko.ru/ports/distfiles/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	IM transparent proxy with monitoring, blocking, and content-filtering

LICENSE=	GPLv2

CFLAGS+=	-fPIC -I ${LOCALBASE}/include -DHAVE_SSL
USE_GMAKE=	YES
USES=		iconv
USE_OPENSSL=	YES
USE_LDCONFIG=	${LOCALBASE}/lib/imspector

CONFIG_FILES=	imspector.conf badwords.txt acl.txt

USE_RC_SUBR=	${PORTNAME}

MAKE_ENV+=	ETCDIR=${ETCDIR}

OPTIONS_DEFINE=	IPFW
OPTIONS_DEFAULT=	IPFW
IPFW_DESC=	Add IPFW support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPFW}
CFLAGS+=	-DIPFW_TRANSPARENT=1
.endif

post-extract:
	${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/imspector.conf \
		${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's,= SSLv23_method(),= (SSL_METHOD *) SSLv23_method(),g' \
		${WRKSRC}/sslstate.cpp
	@${REINPLACE_CMD} -e 's,%%ICONV_LIB%%,${ICONV_LIB},' \
		${WRKSRC}/Makefile

post-install:
.for f in ${CONFIG_FILES}
	@if [ ! -f ${ETCDIR}/${f} ]; then \
		${CP} -p ${ETCDIR}/${f}.sample ${ETCDIR}/${f} ; \
	fi
.endfor

.include <bsd.port.mk>
