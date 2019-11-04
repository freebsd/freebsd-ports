# Created by: ijliao
# $FreeBSD$

PORTNAME=	gss
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Generic Security Service Library

LIB_DEPENDS=	libshishi.so:security/shishi

CONFLICTS=	heimdal-[0-9]*

USES=		libtool localbase:ldflags pathfix pkgconfig perl5
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

post-configure:
	@cd ${WRKSRC}/doc && ${TOUCH} Makefile*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
