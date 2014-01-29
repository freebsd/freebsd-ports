# Created by: ijliao
# $FreeBSD$

PORTNAME=	gss
PORTVERSION=	1.0.2
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU Generic Security Service Library

LIB_DEPENDS=	libshishi.so:${PORTSDIR}/security/shishi

CONFLICTS=	heimdal-[0-9]*

USES=		pathfix pkgconfig perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-kerberos5
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

INFO=		gss
PORTDOCS=	gss.html gss.ps gss.pdf

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-configure:
	@cd ${WRKSRC}/doc && ${TOUCH} Makefile*

pre-install:
	@${MKDIR} ${PREFIX}/${INFO_PATH}

.include <bsd.port.options.mk>

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgss.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
