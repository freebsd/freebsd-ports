# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	netwag
PORTVERSION=	5.38.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/${PORTNAME}/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/${PORTNAME}/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/${PORTNAME}/download/v5/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tgz ${DISTNAME:S/src/doc_html/}.tgz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Graphical front end for netwox

BUILD_DEPENDS=	netwox:net-mgmt/netwox \
		wish8.4:x11-toolkits/tk84 \
		appres:x11/appres \
		xterm:x11/xterm
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

WRKSRC_SUBDIR=	src
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)\.[0-9]*/\1\2/}

PLIST_SUB+=	SHORTPORTVERSION=${SHORTPORTVERSION}

do-configure:
		@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
			 -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			${WRKSRC}/config.dat
		cd ${WRKSRC}; ${SH} ./genemake

post-install:
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${CP} -R ${WRKSRC}/../../${PORTNAME}-${PORTVERSION}-doc_html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
