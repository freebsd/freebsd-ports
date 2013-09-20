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

PLIST_FILES=	bin/multipipe bin/multitail bin/qfilelog bin/spipe \
		bin/tai2tai64n bin/tai64n2tai bin/teepipe
MAN1=		multipipe.1 multitail.1 qfilelog.1 \
		spipe.1 tai2tai64n.1 tai64n2tai.1 teepipe.1
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
do-configure:
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${STRIP} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld

do-install:
	cd ${WRKSRC} && ./installer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
