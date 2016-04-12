# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	netwib
PORTVERSION=	5.38.0
PORTREVISION=	1
CATEGORIES=	net devel ipv6
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwib/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/netwib/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/netwib/download/v5/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tgz ${DISTNAME:S/src/doc_html/}.tgz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Netwib network programming library

LIB_DEPENDS=	libnet.so:net/libnet

WRKSRC_SUBDIR=	src
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)\.[0-9]*/\1\2/}

PLIST_SUB+=	SHORTPORTVERSION=${SHORTPORTVERSION}

post-patch:
	@${REINPLACE_CMD} '/^gccIncLnet=/s/=""/=`libnet-config --cflags`/' \
		${WRKSRC}/genemake
	@${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%CFLAGS%%|${CFLAGS}|' \
		-e 's|gcc|${CC}|' \
		${WRKSRC}/config.dat

do-configure:
	(cd ${WRKSRC} && ${SH} genemake)

.include <bsd.port.mk>
