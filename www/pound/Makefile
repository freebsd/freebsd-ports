# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pound
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}

MAINTAINER=	ncrogers@gmail.com
COMMENT=	Reverse proxy, load balancer and HTTP(S) frontend for web servers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.txt

USES=		tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tcmalloc --disable-hoard
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	NAME=${PORTNAME}

PLIST_FILES=	sbin/pound \
		sbin/poundctl \
		man/man8/pound.8.gz \
		man/man8/poundctl.8.gz
PORTDOCS=	README FAQ CHANGELOG

OPTIONS_DEFINE=	DOCS PCRE
OPTIONS_DEFAULT=PCRE

PCRE_CONFIGURE_ENABLE=	pcreposix

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	libpcre.so:devel/pcre
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pound ${WRKSRC}/poundctl \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pound.8 ${WRKSRC}/poundctl.8 \
		${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
