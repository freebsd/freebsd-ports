PORTNAME=	jail-primer
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	jail-primer1@a1poweruser.com
COMMENT=	Third Generation Jail System Solution

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jail.pristine.fetch		\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.install.system		\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.create.jailcell	\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.delete.jailcell	\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.jailconf.def.create	\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.jailconf.def.delete	\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.jailconf.start		\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.jailconf.stop		\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.rcconf.def.create	\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.rcconf.def.delete	\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.rcconf.start		\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.rcconf.stop		\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.ssh.jailcell		\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jail.jailconf.bootime	\
		${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/jail.rcconf.bootime		\
		${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN}    ${WRKSRC}/jail-primer.8		\
		${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR}	   ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}   ${WRKSRC}/jail-primer.html		\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
