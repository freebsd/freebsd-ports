# $FreeBSD$

PORTNAME=	hawk
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/iphawk/iphawk/Hawk%20${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Track uptime and DNS status for machines on your networks

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask \
		p5-Net-Ping-External>=0:net/p5-Net-Ping-External \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql

USES=		perl5
USE_MYSQL=	server
USE_PHP=	mysql
WANT_PHP_MOD=	yes
IGNORE_WITH_PHP=	70

NO_BUILD=	yes
USE_RC_SUBR=	hawk

SUB_LIST=	PERL=${PERL}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
	    ${WRKSRC}/daemon/hawk
	@${REINPLACE_CMD} -e 's|hawk.conf.inc|${PREFIX}/etc/hawk/php.conf|' \
	    ${WRKSRC}/php/hawk.php

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/daemon/hawk.conf ${STAGEDIR}${ETCDIR}/daemon.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/daemon/hawk ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${WWWDIR}/images
	(for f in ${WRKSRC}/php/images/* ${FILESDIR}/favicon.ico; do \
		${INSTALL_DATA} $$f ${STAGEDIR}${WWWDIR}/images; \
	done)
	${INSTALL_DATA} ${WRKSRC}/php/hawk.php ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/php/hawk.css ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/php/hawk.conf.inc ${STAGEDIR}${ETCDIR}/php.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/create_hawk_db.sql ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/create_hawk_user.sql ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
