PORTNAME=	boinctui
DISTVERSION=	2.7.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Fullscreen text-mode manager for BOINC client
WWW=		https://sourceforge.net/projects/boinctui/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgnutls.so:security/gnutls

USES=		autoreconf gmake localbase ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boinc-dir=/var/db/boinc

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/boinctui

.include <bsd.port.mk>
