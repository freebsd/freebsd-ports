# $FreeBSD$

PORTNAME=	fbopenssl
PORTVERSION=	0.0.4
CATEGORIES=	security
MASTER_SITES=	SF/modgssapache/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GSS-API and SPNEGO extensions for OpenSSL

LICENSE=	GPLv2

USES=		uidfix ssl
USE_LDCONFIG=	yes
MAKEFILE=	BSDMakefile
MAKE_ENV=	BSD_INSTALL_DATA="${INSTALL_DATA}"
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	readme.txt

.if defined(NO_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct asn1_object_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct asn1_object_st'
.endif

post-extract:
	${INSTALL_DATA} ${FILESDIR}/BSDMakefile ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
