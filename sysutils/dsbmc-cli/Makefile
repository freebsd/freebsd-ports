PORTNAME=	dsbmc-cli
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Command-line client for DSBMD
WWW=		https://freeshell.de/~mk/projects/dsbmc-cli.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dsbmd>=0.3:sysutils/dsbmd

USES=		tar:tgz

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man1"

PLIST_FILES=	bin/dsbmc-cli share/man/man1/dsbmc-cli.1.gz

.include <bsd.port.mk>
