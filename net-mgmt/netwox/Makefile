# New ports collection makefile for:	netwox
# Date created:				26.07.2004
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	netwox
PORTVERSION=	5.20.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwox/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/netwox/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/netwox/download/v5/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz ${PORTNAME}-${PORTVERSION}-doc_html.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Netwox a network testing toolbox

BUILD_DEPENDS=	${LOCALBASE}/bin/netwib-config:${PORTSDIR}/net/netwib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/src
USE_REINPLACE=	yes
MAN1=		netwox.1 netwox520.1

do-configure:
		@${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/config.dat
		(cd ${WRKSRC} ; ${SH} ${WRKSRC}/genemake )

post-install:
		strip ${PREFIX}/bin/${PORTNAME}
.ifndef(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${CP} -R ${WRKSRC}/../../${PORTNAME}-${PORTVERSION}-doc_html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
