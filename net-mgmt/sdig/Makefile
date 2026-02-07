PORTNAME=	sdig
PORTVERSION=	0.45
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Translate IP/DNS/WINS/MAC address into port description
WWW=		http://sdig.sourceforge.net

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
CFLAGS+=	-D_WANT_SEMUN

PLIST_FILES=	bin/sdig \
		etc/mactable \
		etc/sdig.conf \
		share/man/man5/sdig.conf.5.gz \
		share/man/man8/sdig.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/sdig.conf
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/sdig.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdig ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sdig.conf ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/mactable ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/sdig.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/sdig.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
