# New ports collection makefile for:	extmail
# Date created:				31 Frebruary 2006
# Whom:					Chifeng QU <chifeng@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	extmail
PORTVERSION=	1.0.1
CATEGORIES=	mail
MASTER_SITES=	http://www.extmail.org/dist/extmail/%SUBDIR%/ \
		http://chifeng.cosoft.org.cn/extmail/%SUBDIR%/

MAINTAINER?=	chifeng@gmail.com
COMMENT=	A high performance webmail system

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

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
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/LDAP.pm:${PORTSDIR}/databases/p5-DBD-LDAP
.endif

OWCGIDIR=	${PREFIX}/www/extmail

do-install:
	@${MKDIR} ${OWCGIDIR}
	@cd ${WRKSRC} && ${CP} -Rpf * ${OWCGIDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
