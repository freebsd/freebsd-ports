# Created by: Cory McIntire (loon@noncensored.com)
# $FreeBSD$

PORTNAME=	lynis
PORTVERSION=	1.3.5
CATEGORIES=	security
MASTER_SITES=	http://cisofy.com/files/

MAINTAINER=	loon@noncensored.com
COMMENT=	Security and system auditing tool

LICENSE=	GPLv3

NO_BUILD=	yes

PORTDOCS=	INSTALL FAQ LICENSE README

post-patch:
	@${REINPLACE_CMD} -e '/tINCLUDE_TARGETS/ s|".*"|"${DATADIR}/include"|; \
		/tPLUGIN_TARGETS/ s|".*"|"${DATADIR}/plugins"|; \
		/tDB_TARGETS/ s|".*"|"${DATADIR}/db"|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/lynis
	${INSTALL_DATA} ${WRKSRC}/default.prf ${STAGEDIR}${PREFIX}/etc/lynis
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "include db dev plugins" ${STAGEDIR}${DATADIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
