# Created by: Chifeng QU <chifeng@gmail.com>

PORTNAME=	policyd2
PORTVERSION=	2.0.14
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	https://download.policyd.org/v${PORTVERSION}/
DISTNAME=	cluebringer-v${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Policyd v2 is a multi-platform policy server for popular MTAs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gsed:textproc/gsed \
		p5-Cache-FastMmap>=0:devel/p5-Cache-FastMmap \
		p5-Config-IniFiles>=0:devel/p5-Config-IniFiles \
		p5-Net-CIDR>=0:net-mgmt/p5-Net-CIDR \
		p5-Net-Server>=0:net/p5-Net-Server

USES=		perl5 shebangfix tar:xz
USE_RC_SUBR=	policyd2
SHEBANG_FILES=	cbpadmin \
		cbpolicyd \
		database/convert-tsql \
		database/whitelists/parse*
bash_CMD=	/bin/sh

WWWDIR=		${PREFIX}/www/policyd

NO_BUILD=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL TODO WISHLIST

OPTIONS_DEFINE=		DOCS MYSQL PGSQL SQLITE WEBUI
OPTIONS_DEFAULT=	MYSQL WEBUI
MYSQL_DESC=		Add a dependency on DBD::mysql
PGSQL_DESC=		Add a dependency on DBD::Pg
SQLITE_DESC=		Add a dependency on DBD:SQLite
WEBUI_DESC=		Add a dependency on the corresponding PHP pdo driver

MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
SQLITE_RUN_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBUI}
. if ${PORT_OPTIONS:MMYSQL}
USES+=		php
USE_PHP=	pdo_mysql
. endif
. if ${PORT_OPTIONS:MSQLITE}
USES+=		php
USE_PHP=	pdo_sqlite
. endif
. if ${PORT_OPTIONS:MPGSQL}
USES+=		php
USE_PHP=	pdo_pgsql
. endif
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/cbpadmin \
		${WRKSRC}/cbpolicyd
	@${REINPLACE_CMD} 's|sed|gsed|' ${WRKSRC}/database/convert-tsql \
		${WRKSRC}/database/whitelists/parse-checkhelo-whitelist \
		${WRKSRC}/database/whitelists/parse-greylisting-whitelist

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR} \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/cbp \
		${STAGEDIR}${DATADIR} \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cbpadmin ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cbpolicyd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cluebringer.conf \
		${STAGEDIR}${PREFIX}/etc/cluebringer.conf.sample
	(cd ${WRKSRC}/webui && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${MV} ${STAGEDIR}${WWWDIR}/includes/config.php \
		${STAGEDIR}${WWWDIR}/includes/config.php.sample
	(cd ${WRKSRC}/cbp && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/cbp)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} contrib ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} database ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
