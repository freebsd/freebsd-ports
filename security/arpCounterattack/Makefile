PORTNAME=	arpCounterattack
PORTVERSION=	1.2.0
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	http://isis.poly.edu/~bk/${PORTNAME}/ \
		http://bk.macroblock.net/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Detects and remedies ARP attacks

LIB_DEPENDS=	libdnet.so:net/libdnet \
		libpcap.so:net/libpcap

USES=		compiler:c++11-lib tar:tbz
USE_CSTD=	c++11
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/arpCounterattack
	${INSTALL_PROGRAM} ${WRKSRC}/arpCounterattack \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/arpCounterattack.conf.sample \
		${WRKSRC}/oui.txt ${STAGEDIR}${PREFIX}/etc/arpCounterattack

.include <bsd.port.mk>
