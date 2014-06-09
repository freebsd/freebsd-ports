# Created by: Ozkan KIRIK <ozkan@enderunix.org>
# $FreeBSD$

PORTNAME=	netustad
PORTVERSION=	0.3.1
PORTREVISION=	6
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.enderunix.org/netustad/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Web based admin tool that manages network services

USE_RC_SUBR=	${PORTNAME}
USES=		gettext
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	SSL NLS
OPTIONS_DEFAULT=SSL
SSL_DESC=	Use netUstad with SSL support

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if empty(PORT_OPTIONS:MNLS)
CONFIGURE_ARGS+=	--without-nls
.endif

.if defined(NOPORTDOCS)
post-patch:
	${REINPLACE_CMD} "s/^install-data-am:.*/install-data-am:/" ${WRKSRC}/Makefile.in
.endif

post-install:
	@${MV} ${STAGEDIR}${ETCDIR}/netustad.conf-dist ${STAGEDIR}${ETCDIR}/netustad.conf.sample

.include <bsd.port.mk>
