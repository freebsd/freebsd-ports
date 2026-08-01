PORTNAME=	mihomo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.29
CATEGORIES=	net games
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rule-based network routing proxy tunnel
WWW=		https://github.com/MetaCubeX/mihomo/tree/Alpha

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26,modules cpe

CPE_VENDOR=	clash_project

GO_MODULE=	github.com/metacubex/mihomo # project is hosted in the GH acct that is Honkai game related but it has nothing to do with gaming

PLIST_FILES=	bin/${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

PORTSCOUT=	limit:^[0-9\.]*$$

pre-patch:
	@cd ${WRKSRC} && ${CP} listener/redir/tcp_linux.go listener/redir/tcp_freebsd.go

.include <bsd.port.mk>
