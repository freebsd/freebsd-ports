# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	libident
PORTVERSION=	0.32
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.remlab.net/files/libident/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small library to interface the ident protocol server (rfc1413)

OPTIONS_DEFINE=	DOCS
USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
