# Created by: Chifeng QU <chifeng@gmail.com>
# $FreeBSD$

PORTNAME=	extmail
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.chifeng.name/dist/extmail/ \
		http://mirror3.extmail.net/dist/

MAINTAINER=	chifeng@gmail.com
COMMENT=	A high performance webmail system

RUN_DEPENDS=	p5-Unix-Syslog>=0:${PORTSDIR}/sysutils/p5-Unix-Syslog

USES=		perl5
NO_BUILD=	yes

OPTIONS_DEFINE=	MYSQL LDAP
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
		${WWWDIR}/tools \
		${WWWDIR}/dispatch-init \
		${WWWDIR}/dispatch.fcgi \
		${WWWDIR}/dispatch_lig.sh \
		-type f -print0 | ${XARGS} -0 ${CHMOD} +x
	@${ECHO_CMD} '@exec ${FIND} \
		${WWWDIR:S,^${PREFIX}/,%D/,}/cgi \
		${WWWDIR:S,^${PREFIX}/,%D/,}/tools \
		${WWWDIR:S,^${PREFIX}/,%D/,}/dispatch-init \
		${WWWDIR:S,^${PREFIX}/,%D/,}/dispatch.fcgi \
		${WWWDIR:S,^${PREFIX}/,%D/,}/dispatch_lig.sh \
		-type f -print0 | ${XARGS} -0 ${CHMOD} +x' >> ${TMPPLIST}

post-install:
	@if [ ! -f ${WWWDIR}/webmail.cf ]; then \
		${CP} -p ${WWWDIR}/webmail.cf.default ${WWWDIR}/webmail.cf ; \
		${CHMOD} +w ${WWWDIR}/webmail.cf ; \
	fi

.include <bsd.port.mk>
