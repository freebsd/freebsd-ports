PORTNAME=	httpfs
PORTVERSION=	2.${VERSION}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}2-${VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fuse-based http filesystem

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/debian/copyright

USES=		fuse pkgconfig gmake

WRKSRC=		${WRKDIR}/${PORTNAME}2-${VERSION}
VERSION=	0.1.5
CFLAGS+=	-D__BSD_VISIBLE
PLIST_FILES=	bin/httpfs2

CERT_STORE=	${LOCALBASE}/share/certs/ca-root-nss.crt
MAKE_ENV+=	CERT_STORE=${CERT_STORE}

OPTIONS_DEFINE=		GNUTLS
OPTIONS_DEFAULT=	GNUTLS

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_RUN_DEPENDS=	${CERT_STORE}:security/ca_root_nss

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httpfs2 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
ALL_TARGET=	full
PLIST_FILES+=	bin/httpfs2-mt bin/httpfs2-ssl bin/httpfs2-ssl-mt
.else
ALL_TARGET=	httpfs2
.endif

do-install-GNUTLS-on:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} httpfs2-mt httpfs2-ssl httpfs2-ssl-mt \
	    ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
