# Created by: ijliao
# $FreeBSD$

PORTNAME=	gss
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU Generic Security Service Library

LIB_DEPENDS=	libshishi.so:security/shishi

CONFLICTS=	heimdal-[0-9]*

BROKEN_FreeBSD_9=	does not build

USES=		libtool pathfix pkgconfig perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-kerberos5
INSTALL_TARGET=	install-strip
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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
