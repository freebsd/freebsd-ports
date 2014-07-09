# Created by: Joe Clarke
# $FreeBSD$

PORTNAME=	openslp
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/OpenSLP/${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Open-source implementation of the Service Location Protocol

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/openslp \
		--localstatedir=/var

USE_RC_SUBR=	slpd

OPTIONS_DEFINE=	SLP_SECURITY ASYNC_API DOCS
SLP_SECURITY_DESC=	Turn on SLPv2 security support
ASYNC_API_DESC=		Enable asynchronous communication API

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSLP_SECURITY}
CONFIGURE_ARGS+=	--enable-slpv2-security
.endif

.if ${PORT_OPTIONS:MASYNC_API}
CONFIGURE_ARGS+=	--enable-async-api
.endif

post-extract:
	@(cd ${WRKSRC}; \
		${FIND} doc -type f -path '*/CVS/*' -delete; \
		${FIND} doc -type d -name CVS -delete)

post-install:
.for FILE in slp.conf slp.reg slp.spi
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} ${STAGEDIR}${PREFIX}/etc/openslp/${FILE}.default
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/doc; \
		${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; ;\
		${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${DOCSDIR}/\{} \;)

.include <bsd.port.mk>
