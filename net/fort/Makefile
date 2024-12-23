PORTNAME=	fort
DISTVERSION=	1.6.4
CATEGORIES=	net

MAINTAINER=	toni@devboks.com
COMMENT=	FORT Validator is an open source RPKI validator
WWW=		https://fortproject.net/en/validator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson
RUN_DEPENDS=	${LOCALBASE}/bin/rsync:net/rsync

USES=		autoreconf compiler:c11 gnome pkgconfig ssl
USE_GNOME=	libxml2
USE_GITHUB=	yes
USE_RC_SUBR=	fort

GH_ACCOUNT=	NICMx
GH_PROJECT=	FORT-validator

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s|/tmp/fort|${ETCDIR}|" \
		${WRKSRC}/examples/config.json
	@${REINPLACE_CMD} -e "s|/usr/local/ssl|/etc/ssl|" \
		${WRKSRC}/examples/config.json
	@${REINPLACE_CMD} -e "s|rsync\",|${LOCALBASE}/bin/rsync\",|" \
		${WRKSRC}/examples/config.json
	@${REINPLACE_CMD} -e "/\"daemon\": false,/d" \
		${WRKSRC}/examples/config.json
post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/repository ${STAGEDIR}${ETCDIR}/tal
	${INSTALL_DATA} ${WRKSRC}/examples/config.json \
		${STAGEDIR}${ETCDIR}/fort-config.json.sample

.include <bsd.port.mk>
