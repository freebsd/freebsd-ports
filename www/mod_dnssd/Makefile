# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_dnssd
PORTVERSION=	0.6
PORTREVISION=	12
CATEGORIES=	www
MASTER_SITES=	http://0pointer.de/lennart/projects/mod_dnssd/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Apache module that provides DNS-SD capabilities

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app

USES=		apache:2.2+ gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	APR_CFLAGS="`${LOCALBASE}/bin/apr-1-config --cflags --cppflags --includes`" \
		APR_LIBS="`${LOCALBASE}/bin/apr-1-config --ldflags`"
CONFIGURE_ARGS=	--disable-lynx

OPTIONS_DEFINE=	DOCS

post-configure:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' ${WRKSRC}/src/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
