PORTNAME=	netwib
PORTVERSION=	5.38.0
PORTREVISION=	2
CATEGORIES=	net devel
MASTER_SITES=	http://www.laurentconstantin.com/common/netw/netwib/download/v5/ \
		http://membres.lycos.fr/lauconstantin/common/netw/netwib/download/v5/ \
		http://laurentconstantin.free.fr/common/netw/netwib/download/v5/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tgz ${DISTNAME:S/src/doc_html/}.tgz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Netwib network programming library

BROKEN_riscv64=		fails to configure: Could not guess NETWIBDEF_SYSARCH. Edit genemake to set NETWIBDEF_SYSARCH, and rerun genemake.

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
