# New ports collection makefile for:	extman
# Date created:				3 April 2007
# Whom:	      				Chifeng QU <chifeng@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	extman
PORTVERSION=	0.2.5
CATEGORIES=	mail
MASTER_SITES=	http://www.chifeng.name/dist/extman/%SUBDIR%/ \
		http://mirror3.extmail.net/dist/%SUBDIR%/

MAINTAINER?=	chifeng@gmail.com
COMMENT=	Web interface to manage Virtual Accounts

USE_PERL5=	yes
NO_BUILD=	yes

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

OPTIONS=	MySQL "Use MySQL support" On \
		LDAP "Use LDAP support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_MySQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif
.if defined(WITH_LDAP)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/LDAP.pm:${PORTSDIR}/databases/p5-DBD-LDAP
.endif

OWCGIDIR=	${PREFIX}/www/extman

do-install:
	@${MKDIR} ${OWCGIDIR}
	@cd ${WRKSRC} && ${CP} -Rpf * ${OWCGIDIR}

.include <bsd.port.post.mk>
