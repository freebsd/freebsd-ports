# Created by: Chifeng QU <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	extman
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.chifeng.name/dist/extman/%SUBDIR%/ \
		http://mirror3.extmail.net/dist/%SUBDIR%/

MAINTAINER=	chifeng@gmail.com
COMMENT=	Web interface to manage Virtual Accounts

RUN_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD

USES=		perl5
NO_BUILD=	yes

OPTIONS_DEFINE=		MYSQL LDAP
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	p5-DBD-LDAP>=0:${PORTSDIR}/databases/p5-DBD-LDAP
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR:S,^${PREFIX}/,%D/,}' >> ${TMPPLIST}

	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR:S,^${PREFIX}/,%D/,} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

	@${FIND} \
		${WWWDIR}/cgi \
		${WWWDIR}/contrib \
		${WWWDIR}/tools \
		${WWWDIR}/addon/mailgraph_ext/mailgraph-init \
		${WWWDIR}/addon/mailgraph_ext/mailgraph_ext.pl \
		${WWWDIR}/addon/mailgraph_ext/qmonitor.pl \
		-type f -print0 | ${XARGS} -0 ${CHMOD} +x
	@${ECHO_CMD} '@exec ${FIND} \
		${WWWDIR:S,^${PREFIX}/,%D/,}/cgi \
		${WWWDIR:S,^${PREFIX}/,%D/,}/contrib \
		${WWWDIR:S,^${PREFIX}/,%D/,}/tools \
		${WWWDIR:S,^${PREFIX}/,%D/,}/addon/mailgraph_ext/mailgraph-init \
		${WWWDIR:S,^${PREFIX}/,%D/,}/addon/mailgraph_ext/mailgraph_ext.pl \
		${WWWDIR:S,^${PREFIX}/,%D/,}/addon/mailgraph_ext/qmonitor.pl \
		-type f -print0 | ${XARGS} -0 ${CHMOD} +x' >> ${TMPPLIST}

post-install:
	@if [ ! -f ${WWWDIR}/webman.cf ]; then \
		${CP} -p ${WWWDIR}/webman.cf.default ${WWWDIR}/webman.cf ; \
		${CHMOD} +w ${WWWDIR}/webman.cf ; \
	fi

.include <bsd.port.mk>
