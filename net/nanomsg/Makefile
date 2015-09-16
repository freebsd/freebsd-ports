# $FreeBSD$

PORTNAME=	nanomsg
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	http://download.nanomsg.org/
DISTNAME=	${PORTNAME}-${DISTVERSION}-beta

MAINTAINER=	crest@bultmann.eu
COMMENT=	Socket library that provides several common communication patterns

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--disable-silent-rules
.endif

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
