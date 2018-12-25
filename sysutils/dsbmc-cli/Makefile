# $FreeBSD$

PORTNAME=	dsbmc-cli
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Command-line client for DSBMD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dsbmd>=0.3:sysutils/dsbmd

USES=		tar:tgz

PLIST_FILES=	bin/dsbmc-cli man/man1/dsbmc-cli.1.gz

.include <bsd.port.mk>
