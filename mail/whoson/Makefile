# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	whoson
PORTVERSION=	2.05
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of `WHO iS ONline' protocol

LICENSE=	PD OpenSSL
LICENSE_COMB=	multi

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-config=${PREFIX}/etc/whoson.conf
USE_LDCONFIG=	yes

USE_RC_SUBR=	whoson

PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/libwhoson.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
