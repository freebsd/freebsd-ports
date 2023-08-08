PORTNAME=	please
PORTVERSION=	3.0
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Execute a command as root
WWW=		https://github.com/MagikBSD/please

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	yes
GH_ACCOUNT=	MagikBSD

PLIST_FILES=	"@(,,4555) bin/please" "@sample etc/pam.d/please.sample" \
		man/man1/please.1.gz

post-install:
	${CP} ${WRKSRC}/pam.d/please.BSD \
		${STAGEDIR}${PREFIX}/etc/pam.d/please.sample

.include <bsd.port.mk>
