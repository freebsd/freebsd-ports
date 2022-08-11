PORTNAME=	tsocks
DISTVERSION=	1.8.b5
PORTREVISION=	8
CATEGORIES=	net security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.8%20beta%205 \
		http://ftp1.sourceforge.net/tsocks/ \
		http://www.yazzy.org/ports/tsocks/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.b/beta/}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Allow non SOCKS aware applications to use SOCKS without modification

LICENSE=	GPLv2

USES=		gmake
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.b.*//}

CONFIGURE_ARGS=	--with-conf=${PREFIX}/etc/tsocks.conf \
		--libdir=${PREFIX}/lib

OPTIONS_DEFINE=	DOCS EXAMPLES HOSTNAMES MUTE OLDMETHOD SOCKSDNS
OPTIONS_DEFAULT=HOSTNAMES

HOSTNAMES_DESC=	Enable DNS lookups
OLDMETHOD_DESC=	Do not use RTLD_NEXT parameter to dlsym
MUTE_DESC=	Disable all error messages
SOCKSDNS_DESC=	Intercept DNS requests and attempt to force them to use TCP

HOSTNAMES_CONFIGURE_OFF=	--disable-hostnames
MUTE_CONFIGURE_ON=	--disable-debug
OLDMETHOD_CONFIGURE_ON=	--enable-oldmethod
SOCKSDNS_CONFIGURE_ON=	--enable-socksdns

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|ufds|fds|g' ${WRKSRC}/tsocks.c
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/tsocks

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/inspectsocks ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/validateconf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tsocks.conf.simple.example \
		${STAGEDIR}${PREFIX}/etc/tsocks.conf.sample
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.example ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}/README
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
