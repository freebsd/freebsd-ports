PORTNAME=	elog
DISTVERSION=	3.1.5-1
CATEGORIES=	www
MASTER_SITES=	https://elog.psi.ch/elog/download/tar/

MAINTAINER=	erik@tenku.dk
COMMENT=	Fast and lightweight, customizable weblog
WWW=		https://elog.psi.ch/elog/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ssl

USE_RC_SUBR=	elogd

USERS=	elog
GROUPS=	elog

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/elconv ${STAGEDIR}${PREFIX}/bin/elconv
	${INSTALL_PROGRAM} ${WRKSRC}/elog ${STAGEDIR}${PREFIX}/bin/elog
	${INSTALL_MAN} ${WRKSRC}/man/elconv.1 ${STAGEDIR}${PREFIX}/share/man/man1/elconv.1
	${INSTALL_MAN} ${WRKSRC}/man/elog.1 ${STAGEDIR}${PREFIX}/share/man/man1/elog.1
	${INSTALL_MAN} ${WRKSRC}/man/elogd.8 ${STAGEDIR}${PREFIX}/share/man/man8/elogd.8
	${INSTALL_PROGRAM} ${WRKSRC}/elogd ${STAGEDIR}${PREFIX}/sbin
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "logbooks resources scripts themes" ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/elogd.cfg.example ${STAGEDIR}${PREFIX}/etc/elogd.cfg.sample
	${MKDIR} ${STAGEDIR}${WWWDIR}/ssl

do-install-DOCS-on:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "doc" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
