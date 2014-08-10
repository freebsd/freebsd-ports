# Created by: Chifeng QU <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	policyd2
PORTVERSION=	2.0.12
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://devlabs.linuxassist.net/attachments/download/${DOWNLOAD_FOLDER}/
DISTNAME=	cluebringer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Policyd v2 is a multi-platform policy server for popular MTAs

RUN_DEPENDS=	p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Net-CIDR>=0:${PORTSDIR}/net-mgmt/p5-Net-CIDR \
		p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-Cache-FastMmap>=0:${PORTSDIR}/devel/p5-Cache-FastMmap

USES=		perl5 shebangfix
NO_BUILD=	yes
BINMODE=	0755
USE_RC_SUBR=	policyd2
DOWNLOAD_FOLDER=	222
BASH_CMD=	/bin/sh
SHEBANG_FILES=	cbpadmin \
		cbpolicyd \
		database/convert-tsql \
		database/whitelists/parse*

WEBUIDIR=	${PREFIX}/www/policyd
PORTDOCS=	AUTHORS ChangeLog INSTALL TODO WISHLIST
PORTDATA=	*

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE WEBUI
OPTIONS_DEFAULT=MYSQL WEBUI

MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
SQLITE_RUN_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBUI}
. if ${PORT_OPTIONS:MMYSQL}
USE_PHP=	pdo_mysql
. endif
. if ${PORT_OPTIONS:MSQLITE}
USE_PHP=	pdo_sqlite
. endif
. if ${PORT_OPTIONS:MPGSQL}
USE_PHP=	pdo_pgsql
. endif
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/cbpadmin \
		${WRKSRC}/cbpolicyd

do-install:
	@${INSTALL} -d ${STAGEDIR}${WEBUIDIR} ${STAGEDIR}${SITE_PERL}/cbp
	cd ${WRKSRC}/webui && ${COPYTREE_SHARE} \* ${STAGEDIR}${WEBUIDIR}
	cd ${WRKSRC}/cbp && ${COPYTREE_SHARE} \* ${STAGEDIR}${SITE_PERL}/cbp
	${INSTALL_SCRIPT} ${WRKSRC}/cbpadmin ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cbpolicyd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cluebringer.conf ${STAGEDIR}${PREFIX}/etc/cluebringer.conf.sample
	@${INSTALL} -d ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} contrib ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} database ${STAGEDIR}${DATADIR}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

	@${ECHO_MSG}
	@${ECHO_MSG} "Please check INSTALL file to configure!"
	@${ECHO_MSG}

.include <bsd.port.mk>
