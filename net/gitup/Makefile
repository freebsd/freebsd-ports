# $FreeBSD$

PORTNAME=	gitup
DISTVERSION=	0.87
CATEGORIES=	net

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Minimalist, dependency-free program to clone/pull git repositories

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl

USE_GITHUB=	yes
GH_ACCOUNT=	johnmehr

ALL_TARGET=	gitup
CFLAGS+=	-I${OPENSSLINC}
LDADD=		-lz -L${OPENSSLLIB} -lssl -lcrypto -lprivateucl
MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		LDADD="${LDADD}"

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's,\./gitup.conf,${PREFIX}/etc/gitup.conf,' \
		${WRKSRC}/gitup.c
	${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/gitup.1 ${WRKSRC}/gitup.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gitup.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/gitup.conf.5  ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/gitup.conf \
		${STAGEDIR}${PREFIX}/etc/gitup.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
