PORTNAME=	lambdamoo
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF
DISTNAME=	LambdaMOO-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The most commonly used program to run MOOs
WWW=		https://www.moo.mud.org/

LICENSE=	XEROX
LICENSE_NAME=	unknown
LICENSE_FILE=	${WRKSRC}/server.c
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf:build bison
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	YACC=${YACC}

WRKSRC=		${WRKDIR}/MOO-${PORTVERSION}

PLIST_FILES=	sbin/moo
PORTDOCS=	*

ALL_TARGET=

OPTIONS_DEFINE=	DOCS

	# needs to run just autoconf, autoreconf doesn't work
pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf${_AUTORECONF}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} Minimal.db README README.Minimal \
		${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
