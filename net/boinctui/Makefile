PORTNAME=	boinctui
DISTVERSION=	2.7.1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Fullscreen text-mode manager for BOINC client
WWW=		https://sourceforge.net/projects/boinctui/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		autoreconf gmake localbase ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boinc-dir=/var/db/boinc

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFAULT=	GNUTLS
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--without-gnutls

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
