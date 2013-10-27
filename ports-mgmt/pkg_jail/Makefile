# $FreeBSD$

PORTNAME=	pkg_jail
PORTVERSION=	1.73
CATEGORIES=	ports-mgmt
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Manage your own package jail

NO_BUILD=	yes

USES=		manpages:install
MANSRC=		${FILESDIR}
PLIST_FILES=	bin/pkg_jail bin/pkg_update
PORTDOCS=	README
MAN1=		pkg_jail.1 pkg_update.1

.include <bsd.port.options.mk>

do-install:	install-all-manpages
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_jail ${FILESDIR}/pkg_update \
		${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${STAGEDIR}${DOCSDIR}/
.endif

install-ports:
	-${MKDIR} ${PORTSDIR}/local/update/data
	${LN} -s ${FILESDIR}/README ${PORTSDIR}/local/update/
	${LN} -s ${FILESDIR}/pkg_update ${PORTSDIR}/local/update/
	${LN} -s ${FILESDIR}/pkg_jail ${PORTSDIR}/local/update/

.include <bsd.port.mk>
