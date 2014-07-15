# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	netwib
PORTVERSION=	5.38.0
PORTREVISION=	1
CATEGORIES=	net devel ipv6
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwib/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/netwib/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/netwib/download/v5/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz ${PORTNAME}-${PORTVERSION}-doc_html.tgz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Netwib network programming library

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/src
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)\.[0-9]*/\1\2/}

PLIST_SUB+=	SHORTPORTVERSION=${SHORTPORTVERSION}

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|libnet-config|${LIBNET_CONFIG}|; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|; \
		 s|^(gccIncLnet=).*|\1"`${LIBNET_CONFIG} --cflags`"|' \
		 ${WRKSRC}/genemake

do-configure:
		@${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%CFLAGS%%|${CFLAGS}|' \
		-e 's|gcc|${CC}|' \
		${WRKSRC}/config.dat
		(cd ${WRKSRC} ; ${SH} ${WRKSRC}/genemake )

.include <bsd.port.mk>
