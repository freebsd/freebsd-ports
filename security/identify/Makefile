PORTNAME=	identify
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://ftp.nluug.nl/ftp/pub/pub/security/coast/daemons/pidentd/tools/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Client side ident protocol daemon wrapper
WWW=		http://ftp.nluug.nl/ftp/pub/pub/security/coast/daemons/pidentd/tools/

LICENSE=	PD

BUILD_DEPENDS=	${LOCALBASE}/lib/libident.a:security/libident

PLIST_FILES=	libexec/identify
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/identify ${STAGEDIR}${PREFIX}/libexec

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
