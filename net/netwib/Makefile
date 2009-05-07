# New ports collection makefile for:	netwox
# Date created:				23.07.2004
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	netwib
PORTVERSION=	5.36.0
CATEGORIES=	net devel ipv6
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwib/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/netwib/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/netwib/download/v5/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz ${PORTNAME}-${PORTVERSION}-doc_html.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Netwib network programming library

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/src
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)\.[0-9]*/\1\2/}
MAN3=		netwib.3 netwib_dat.3 netwib_err.3 netwib_net.3 \
		netwib_pkt.3 netwib_shw.3 netwib_sys.3
MAN3+=		netwib${SHORTPORTVERSION}.3 netwib${SHORTPORTVERSION}_dat.3 \
		netwib${SHORTPORTVERSION}_err.3 \
		netwib${SHORTPORTVERSION}_net.3 \
		netwib${SHORTPORTVERSION}_pkt.3 \
		netwib${SHORTPORTVERSION}_shw.3 \
		netwib${SHORTPORTVERSION}_sys.3

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800059
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
