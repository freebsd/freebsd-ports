PORTNAME=	portoptscli
DISTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt accessibility

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to set up FreeBSD ports options
WWW=		https://gitlab.com/alfix/portoptscli

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_ACCOUNT=	alfix

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
