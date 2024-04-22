PORTNAME=	pkgs_which
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Quickly find out which ports contributed to a file tree

LICENSE=	GPLv3

USES=		perl5
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.options.mk>

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/bin
		${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${PREFIX}/man/man1
		${LOCALBASE}/bin/pod2man ${FILESDIR}/${PORTNAME} >${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
