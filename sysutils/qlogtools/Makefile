# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	qlogtools
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for processing logs from qmail and other packages

LICENSE=	GPLv2

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

do-configure:
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${STAGEDIR}${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${STRIP} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld

do-install:
	cd ${WRKSRC} && ./installer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
