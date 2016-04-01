# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	netwox
PORTVERSION=	5.38.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwox/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/netwox/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/netwox/download/v5/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tgz ${DISTNAME:S/src/doc_html/}.tgz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Netwox a network testing toolbox

BUILD_DEPENDS=	netwib-config:net/netwib

OPTIONS_DEFINE=	DOCS

WRKSRC_SUBDIR=	src
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)\.[0-9]*/\1\2/}

PLIST_SUB+=	SHORTPORTVERSION=${SHORTPORTVERSION}

MAKE_JOBS_UNSAFE=	yes

do-configure:
		@${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%CFLAGS%%|${CFLAGS}|' \
		-e 's|gcc|${CC}|' \
		${WRKSRC}/config.dat
		(cd ${WRKSRC} ; ${SH} ${WRKSRC}/genemake )

post-install:
		@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${CP} -R ${WRKSRC}/../../${PORTNAME}-${PORTVERSION}-doc_html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
