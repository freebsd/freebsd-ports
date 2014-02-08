# Created by: Marcin Jessa <freebsd@yazzy.org>
# $FreeBSD$

PORTNAME=	tsocks
PORTVERSION=	1.8.b5
PORTREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.8%20beta%205 \
		http://ftp1.sourceforge.net/tsocks/ \
		http://www.yazzy.org/ports/tsocks/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.b/beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allow non SOCKS aware applications to use SOCKS without modification

GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes

WRKSRC=${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.b.*//}

CONFIGURE_ARGS=	--with-conf=${PREFIX}/etc/tsocks.conf \
		--libdir=${PREFIX}/lib

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES HOSTNAMES OLDMETHOD SOCKSDNS
OPTIONS_DEFAULT=	DEBUG HOSTNAMES

DEBUG_DESC=	Output error messages to stderr
HOSTNAMES_DESC=	Enable DNS lookups
OLDMETHOD_DESC=	Do not use RTLD_NEXT parameter to dlsym
SOCKSDNS_DESC=	Intercept DNS requests and attempt to force them to use TCP

DEBUG_CONFIGURE_OFF=	--disable-debug
HOSTNAMES_CONFIGURE_OFF=	--disable-hostnames
OLDMETHOD_CONFIGURE_ON=	--enable-oldmethod
SOCKSDNS_CONFIGURE_ON=	--enable-socksdns

post-patch:
	@${REINPLACE_CMD} -e 's|ufds|fds|g' ${WRKSRC}/tsocks.c
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/tsocks

post-install:
	${INSTALL_DATA} ${WRKSRC}/tsocks.conf.simple.example ${STAGEDIR}${PREFIX}/etc/tsocks.conf.sample
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.example ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
