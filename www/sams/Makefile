# New ports collection makefile for:  sams
# Date created:		12 December 2006
# Whom:			dindin
#
# $FreeBSD$
#

PORTNAME=	sams
DISTVERSION=	1.0.3
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
		APACHE2	"Use apache version 2"	on

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PHP=	gd mysql ldap
USE_MYSQL=	5.0

CONFIGURE_ARGS=	--with-configfile=${LOCALBASE}/etc/sams.conf \
		--with-rcd-locations=${LOCALBASE}/etc/rc.d/ \
		--with-httpd-locations=${DOCUMENT_ROOT}

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_NTLM)
RUN_DEPENDS=	 ${LOCALBASE}/bin/ntlm_auth:${PORTSDIR}/net/samba3
.endif

.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13
.else
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache22
.endif

post-extract:
	${INSTALL_SCRIPT} ${FILESDIR}/setup.sh ${WRKSRC}/

post-install:
	@${CAT} ${PKGMESSAGE}

setup:
	@cd ${WRKSRC}; ${WRKSRC}/setup.sh

.include <bsd.port.post.mk>
