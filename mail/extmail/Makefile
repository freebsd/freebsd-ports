# New ports collection makefile for:	extmail
# Date created:				31 Frebruary 2006
# Whom:					Chifeng QU <chifeng@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	extmail
PORTVERSION=	1.1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.chifeng.name/dist/extmail/ \
		http://mirror3.extmail.net/dist/

MAINTAINER?=	chifeng@gmail.com
COMMENT=	A high performance webmail system

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog

USE_PERL5=	yes
NO_BUILD=	yes

OPTIONS=	MYSQL "Use MySQL support" On \
		LDAP "Use LDAP support" Off

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif
.if defined(WITH_LDAP)
RUN_DEPENDS+=	${SITE_PERL}/DBD/LDAP.pm:${PORTSDIR}/databases/p5-DBD-LDAP
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${CP} -Rfp * ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
