# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pound
PORTVERSION=	2.8
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}

EXTRA_PATCHES=	\
	${FILESDIR}/0001-Add-MKCALENDAR-to-xHTTP-2-and-above.patch:-p1 \
	${FILESDIR}/0002-add-support-openssl1.1-dhparam.patch:-p1 \
	${FILESDIR}/c5a95780e2233a05ab3fb8b4eb8a9550f0c3b53c.patch:-p1 \
	${FILESDIR}/pound-2.8-websocket.diff:-p1 \
	${FILESDIR}/pound-2.8-fallback_scsv.diff:-p0 \
	${FILESDIR}/a2c9dde4d055ea8942afb150b7fc3a807d4e5d60.patch:-p1

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	HTTP/HTTPS reverse-proxy and load-balancer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.txt

USES=		tar:tgz ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tcmalloc --disable-hoard
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	${PORTNAME}.cfg
SUB_LIST=	NAME=${PORTNAME}

PLIST_FILES=	@sample\ etc/pound.cfg.sample \
		sbin/pound \
		sbin/poundctl \
		man/man8/pound.8.gz \
		man/man8/poundctl.8.gz
PORTDOCS=	README FAQ CHANGELOG

OPTIONS_DEFINE=	DOCS DSAPARAM PCRE
OPTIONS_DEFAULT=PCRE
DSAPARAM_DESC=	Generate DH parameters without using "safe" primes

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_USES=	localbase
PCRE_CONFIGURE_ENABLE=	pcreposix

post-patch-DSAPARAM-on:
	@${REINPLACE_CMD} -e '/openssl dhparam/s,-5,-dsaparam,' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
