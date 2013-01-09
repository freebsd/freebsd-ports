# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	netwag
PORTVERSION=	5.38.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/${PORTNAME}/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/${PORTNAME}/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/${PORTNAME}/download/v5/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz ${PORTNAME}-${PORTVERSION}-doc_html.tgz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	A graphical front end for netwox

BUILD_DEPENDS=	netwox:${PORTSDIR}/net-mgmt/netwox \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		appres:${PORTSDIR}/x11/appres \
		xterm:${PORTSDIR}/x11/xterm
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/src
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)\.[0-9]*/\1\2/}
MAN1=		${PORTNAME}.1 ${PORTNAME}${SHORTPORTVERSION}.1

PLIST_SUB+=	SHORTPORTVERSION=${SHORTPORTVERSION}

do-configure:
		@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
			 -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			${WRKSRC}/config.dat
		cd ${WRKSRC}; ${SH} ./genemake

post-install:
.ifndef(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${CP} -R ${WRKSRC}/../../${PORTNAME}-${PORTVERSION}-doc_html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
