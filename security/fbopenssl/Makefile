# $FreeBSD$

PORTNAME=	fbopenssl
PORTVERSION=	0.0.4
CATEGORIES=	security
MASTER_SITES=	SF/modgssapache/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GSS-API and SPNEGO extensions for OpenSSL

LICENSE=	GPLv2

USE_LDCONFIG=	yes
USE_OPENSSL=	yes
MAKEFILE=	BSDMakefile
MAKE_ENV=	BSD_INSTALL_DATA="${BSD_INSTALL_DATA}"
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	${INSTALL_DATA} ${FILESDIR}/BSDMakefile ${WRKSRC}

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
