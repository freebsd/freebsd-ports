# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pound
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reverse proxy, load balancer and HTTP(S) frontend for web servers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.txt

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	NAME=${PORTNAME}

MAN8=	pound.8 poundctl.8

OPTIONS_DEFINE=	MSDAV PCRE
OPTIONS_DEFAULT=	PCRE
MSDAV_DESC=	Microsoft WebDAV extension support

CONFIGURE_ARGS=	--disable-tcmalloc --disable-hoard
PLIST_FILES=	sbin/pound sbin/poundctl
PORTDOCS=	README FAQ CHANGELOG

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMSDAV}
CONFIGURE_ARGS+=	--enable-msdav
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=		libpcre.so:${PORTSDIR}/devel/pcre
CFLAGS+=		"-I${LOCALBASE}/include"
CPPFLAGS+=		"-I${LOCALBASE}/include"
LDFLAGS+=		"-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-pcreposix
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
