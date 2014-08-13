# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pound
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reverse proxy, load balancer and HTTP(S) frontend for web servers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.txt

USES=		tar:tgz
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	NAME=${PORTNAME}

OPTIONS_DEFINE=	MSDAV PCRE
OPTIONS_DEFAULT=PCRE
MSDAV_DESC=	Microsoft WebDAV extension support

PCRE_CONFIGUE_ENABLE=	pcreposix
MSDAV_CONFIGURE_ENABLE=	msdav
CONFIGURE_ARGS=		--disable-tcmalloc --disable-hoard

PLIST_FILES=	sbin/pound \
		sbin/poundctl \
		man/man8/pound.8.gz \
		man/man8/poundctl.8.gz
PORTDOCS=	README FAQ CHANGELOG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=		libpcre.so:${PORTSDIR}/devel/pcre
CFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pound ${WRKSRC}/poundctl \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pound.8 ${WRKSRC}/poundctl.8 \
		${STAGEDIR}${MANPREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
