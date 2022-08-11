PORTNAME=	sdig
PORTVERSION=	0.45
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Translate IP/DNS/WINS/MAC address into port description

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
CFLAGS+=	-D_WANT_SEMUN

PLIST_FILES=	bin/sdig \
		etc/mactable \
		etc/sdig.conf \
		man/man5/sdig.conf.5.gz \
		man/man8/sdig.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/sdig.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/sdig.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdig ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sdig.conf ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/mactable ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/sdig.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/sdig.conf.5 ${STAGEDIR}${PREFIX}/man/man5

.include <bsd.port.mk>
