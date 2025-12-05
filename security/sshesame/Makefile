PORTNAME=	sshesame
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.39
CATEGORIES=	security

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Easy to set up and use SSH honeypot
WWW=		https://github.com/jaksi/sshesame

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules
USE_RC_SUBR=	${PORTNAME}

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

USERS=		sshesame
GROUPS=		sshesame

GO_MODULE=	github.com/jaksi/sshesame

PLIST_FILES=	"@sample etc/${PORTNAME}.yaml.sample" \
		bin/${PORTNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.yaml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yaml.sample

.include <bsd.port.mk>
