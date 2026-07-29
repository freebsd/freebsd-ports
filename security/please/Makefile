PORTNAME=	please
DISTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Execute a command as root
WWW=		https://github.com/gblach/please

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

DEPRECATED=		Upstream project has been archived, use doas or sudo or sudo-rs instead
EXPIRATION_DATE=	2026-08-26

USE_GITHUB=	yes
GH_ACCOUNT=	gblach

PLIST_FILES=	"@(,,4555) bin/please" "@sample etc/pam.d/please.sample" \
		share/man/man1/please.1.gz

post-install:
	${CP} ${WRKSRC}/pam.d/please.BSD \
		${STAGEDIR}${PREFIX}/etc/pam.d/please.sample

.include <bsd.port.mk>
