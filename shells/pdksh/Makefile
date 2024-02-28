PORTNAME=	pdksh
PORTVERSION=	5.2.14p2
PORTREVISION=	7
CATEGORIES=	shells
MASTER_SITES= https://ftp.lip6.fr/pub/unix/shells/pdksh/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/p.*//}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-patches.1.gz ${DISTNAME}-patches.2.gz
PATCH_DIST_STRIP=	-p2

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	The Public Domain Korn Shell
WWW=		http://www.cs.mun.ca/~michael/pdksh/

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
CPP+=		-P

OPTIONS_DEFINE=	STATIC

STATIC_CONFIGURE_ENV+=	LDSTATIC=-static

post-patch:
	@(${ECHO_CMD} ",s/v${PORTVERSION:C/p.*//}/v${PORTVERSION:S/p/./}/"; \
		${ECHO_CMD} "wq") | ed -s ${WRKSRC}/version.c

.include <bsd.port.mk>
