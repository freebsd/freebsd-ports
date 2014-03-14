# Created by: Maxim Tuliuk <mt@primats.org.ua>
# $FreeBSD$

PORTNAME=	ipplan
PORTVERSION=	4.92b
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/iptrack/${PORTNAME}/Release%204.92

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	IP address management and tracking

RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

USES=		perl5 shebangfix
USE_PERL5=	run
USE_PHP=	gettext pcre xml zlib
SHEBANG_FILES=	${WRKSRC}/contrib/process-exports.pl ${WRKSRC}/contrib/ipplan-poller.php

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIG=		config.php
SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=	MYSQL PGSQL SNMP
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSNMP}
USE_PHP+=	snmp
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin/xsltproc|${LOCALBASE}/bin/xsltproc|" \
		${WRKSRC}/contrib/process-exports.pl
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/${CONFIG}
	@${MV} ${WRKSRC}/${CONFIG} ${WRKSRC}/${CONFIG}.sample
	@${RM} ${WRKSRC}/${CONFIG}.orig

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

post-install:
	# make /var dirs
	${MKDIR} ${STAGEDIR}/var/spool/ipplan/dhcpexport
	${MKDIR} ${STAGEDIR}/var/spool/ipplan/exportdns
	${MKDIR} ${STAGEDIR}/var/spool/ipplan/uploads
.if ${PORT_OPTIONS:MPGSQL}
	@${REINPLACE_CMD} -e 's|INSTALL|INSTALL-POSTGRESQL|g' ${PKGMESSAGE}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
