# New ports collection makefile for:	policyd2
# Date created:				2 December 2008
# Whom:	      				Chifeng QU <chifeng@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	policyd2
PORTVERSION=	2.0.12
CATEGORIES=	mail
MASTER_SITES=	http://devlabs.linuxassist.net/attachments/download/${DOWNLOAD_FOLDER}/
DISTNAME=	cluebringer-${PORTVERSION}

MAINTAINER=	chifeng@gmail.com
COMMENT=	Policyd v2 is a multi-platform policy server for popular MTAs

RUN_DEPENDS=	p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Net-CIDR>=0:${PORTSDIR}/net-mgmt/p5-Net-CIDR \
		p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-Cache-FastMmap>=0:${PORTSDIR}/devel/p5-Cache-FastMmap

USES=		perl5
USE_PHP=	yes
NO_BUILD=	yes
USE_RC_SUBR=	policyd2
BINMODE=	0755
DOWNLOAD_FOLDER=	222

WEBUIDIR=	${PREFIX}/www/policyd
PORTDOCS=	AUTHORS ChangeLog INSTALL TODO WISHLIST
PORTDATA=	*

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.pre.mk>
USE_PHP=	pdo_mysql
.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif
.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
.endif
.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/cbpadmin \
		${WRKSRC}/cbpolicyd

do-install:
	@${INSTALL} -d ${WEBUIDIR} ${SITE_PERL}/cbp
	@cd ${WRKSRC}/webui && ${COPYTREE_SHARE} \* ${WEBUIDIR}
	@cd ${WRKSRC}/cbp && ${COPYTREE_SHARE} \* ${SITE_PERL}/cbp
	${INSTALL_SCRIPT} ${WRKSRC}/cbpadmin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cbpolicyd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cluebringer.conf ${PREFIX}/etc/cluebringer.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/cluebringer.conf ]; then \
		${INSTALL_DATA} -m 666 ${PREFIX}/etc/cluebringer.conf.sample ${PREFIX}/etc/cluebringer.conf ;\
	fi

.if !defined(NOPORTDATA)
	@${INSTALL} -d ${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} contrib ${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} database ${DATADIR}
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${ECHO_MSG}
	@${ECHO_MSG} "Please check INSTALL file to configure!"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
