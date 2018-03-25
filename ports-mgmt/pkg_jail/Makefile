# $FreeBSD$

PORTNAME=	pkg_jail
PORTVERSION=	2.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Manage your own package jail

LICENSE=	BSD3CLAUSE

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/pkg_jail bin/pkg_update \
		man/man1/pkg_jail.1.gz man/man1/pkg_update.1.gz
PORTDOCS=	README.txt
LMAN1=		pkg_jail.1 pkg_update.1

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_jail ${FILESDIR}/pkg_update \
		${STAGEDIR}${PREFIX}/bin/
.for i in ${LMAN1}
	${INSTALL_MAN} ${FILESDIR}/${i} ${STAGEDIR}${PREFIX}/man/man1/
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.txt ${STAGEDIR}${DOCSDIR}/

install-ports:
	-${MKDIR} ${PORTSDIR}/local/update/data
	${LN} -s ${FILESDIR}/README.txt ${PORTSDIR}/local/update/
	${LN} -s ${FILESDIR}/pkg_update ${PORTSDIR}/local/update/
	${LN} -s ${FILESDIR}/pkg_jail ${PORTSDIR}/local/update/

.include <bsd.port.mk>
