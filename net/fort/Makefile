PORTNAME=	fort
DISTVERSION=	1.6.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/NICMx/FORT-validator/releases/download/${DISTVERSION}/

MAINTAINER=	toni@devboks.com
COMMENT=	FORT Validator is an open source RPKI validator
WWW=		https://fortproject.net/en/validator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson
RUN_DEPENDS=	${LOCALBASE}/bin/rsync:net/rsync

USES=		gnome localbase:ldflags pkgconfig ssl
USE_GNOME=	libxml2
USE_RC_SUBR=	fort

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s|-O2 -g||" \
		${PATCH_WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|/tmp/fort|${ETCDIR}|" \
		${PATCH_WRKSRC}/examples/config.json
	@${REINPLACE_CMD} -e "s|/usr/local/ssl|/etc/ssl|" \
		${PATCH_WRKSRC}/examples/config.json
	@${REINPLACE_CMD} -e "s|rsync\",|${LOCALBASE}/bin/rsync\",|" \
		${PATCH_WRKSRC}/examples/config.json
	@${REINPLACE_CMD} -e "/\"daemon\": false,/d" \
		${PATCH_WRKSRC}/examples/config.json
post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/repository ${STAGEDIR}${ETCDIR}/tal
	${INSTALL_DATA} ${WRKSRC}/examples/config.json \
		${STAGEDIR}${ETCDIR}/fort-config.json.sample

.include <bsd.port.mk>
