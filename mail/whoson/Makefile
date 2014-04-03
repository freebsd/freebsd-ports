# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	whoson
PORTVERSION=	2.05
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Implementation of `WHO iS ONline' protocol

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-config=${PREFIX}/etc/whoson.conf
USE_LDCONFIG=	yes

USE_RC_SUBR=	whoson

PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/libwhoson.so.0

.include <bsd.port.mk>
