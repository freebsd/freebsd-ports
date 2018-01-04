# Created by: Cory McIntire (loon@noncensored.com)
# $FreeBSD$

PORTNAME=	lynis
PORTVERSION=	2.5.8
CATEGORIES=	security
MASTER_SITES=	https://cisofy.com/files/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Security and system auditing tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lsof:sysutils/lsof

USES=		cpe
CPE_VENDOR=	cisofy
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	FAQ README

post-patch:
	@${REINPLACE_CMD} -e '/tINCLUDE_TARGETS/ s|".*"|"${DATADIR}/include"|; \
		/tPLUGIN_TARGETS/ s|".*"|"${DATADIR}/plugins"|; \
		/tDB_TARGETS/ s|".*"|"${DATADIR}/db"|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/default.prf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/default.prf.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "include db plugins" ${STAGEDIR}${DATADIR}/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/extras/bash_completion.d/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
