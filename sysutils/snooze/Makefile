# $FreeBSD$

PORTNAME=	snooze
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Run a command at a particular time

LICENSE=	CC0-1.0

USE_GITHUB=	yes
GH_ACCOUNT=	leahneukirchen

MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		MANDIR="${PREFIX}/man" \
		PREFIX="${PREFIX}"

PLIST_FILES=	bin/snooze \
		man/man1/snooze.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/snooze

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
