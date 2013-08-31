# Created by: ijliao
# $FreeBSD$

PORTNAME=	gss
PORTVERSION=	1.0.2
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU Generic Security Service Library

LIB_DEPENDS=	shishi.1:${PORTSDIR}/security/shishi

CONFLICTS=	heimdal-[0-9]*

USES=		pathfix pkgconfig perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-kerberos5
USE_LDCONFIG=	yes

INFO=		gss
PORTDOCS=	gss.html gss.ps gss.pdf

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include "Makefile.man"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-configure:
	@cd ${WRKSRC}/doc && ${TOUCH} Makefile*

pre-install:
	@${MKDIR} ${PREFIX}/${INFO_PATH}

post-install:
.ifndef	NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
