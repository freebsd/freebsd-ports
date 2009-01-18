# New ports collection makefile for:  sams
# Date created:		12 December 2006
# Whom:			dindin
#
# $FreeBSD$
#

PORTNAME=	sams
DISTVERSION=	1.0.4
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://sams.perm.ru/download/ \
		http://grishin.000webhost.info/sams/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	uzgrishin@mail.ru
COMMENT=	Squid 2.x Accounting Management System

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_RC_SUBR=	sams.sh

OPTIONS=	NTLM	"NTLM autorization/ActiveDirectory support"	off \
		APACHE22	"Use apache version 2.2"	on \
		PHP5GD	"Enable constructing graphs" on

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PHP=	mysql
USE_MYSQL=	5.0

CONFIGURE_ARGS=	--with-configfile=${LOCALBASE}/etc/sams.conf \
		--with-rcd-locations=${LOCALBASE}/etc/rc.d/

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_NTLM)
RUN_DEPENDS=	${LOCALBASE}/bin/ntlm_auth:${PORTSDIR}/net/samba3
RUN_DEPENDS+=	${LOCALBASE}/include/php/ext/ldap/php_ldap.h:${PORTSDIR}/net/php5-ldap/
.endif

.if defined(WITH_PHP5GD)
RUN_DEPENDS+=	${LOCALBASE}/include/php/ext/gd/php_gd.h:${PORTSDIR}/graphics/php5-gd/
.endif

.if defined(WITH_APACHE22)
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache22
.else
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13
.endif

post-extract:
	${INSTALL_SCRIPT} ${FILESDIR}/setup.sh ${WRKSRC}/

post-install:
	@${CAT} ${PKGMESSAGE}

setup:
	@cd ${WRKSRC}; ${WRKSRC}/setup.sh

.include <bsd.port.post.mk>
