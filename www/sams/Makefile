# New ports collection makefile for:  sams
# Date created:		12 December 2006
# Whom:			dindin
#
# $FreeBSD$
#

PORTNAME=	sams
DISTVERSION=	1.0.5
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://sams.perm.ru/download/ \
		http://gateway11.ath.cx/sams/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Squid 2.x Accounting Management System

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

SAMBA_PORT?=	net/samba34

USE_RC_SUBR=	sams

OPTIONS=	NTLM	"NTLM autorization/ActiveDirectory support"	off \
		INSTALLGD 	"Graphic reports"		on

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PHP=	ctype curl gettext hash iconv json mysql \
		pcre pdo pdo_sqlite posix session \
		simplexml spl sqlite tokenizer \
		xmlwriter zlib xmlreader
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
MANUAL_PACKAGE_BUILD=	it needs an old PHP version

USE_MYSQL=	5.0

CONFIGURE_ARGS=	--with-configfile=${PREFIX}/etc/sams.conf \
		--with-rcd-locations=${PREFIX}/etc/rc.d/

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_NTLM)
RUN_DEPENDS=	${LOCALBASE}/bin/ntlm_auth:${PORTSDIR}/${SAMBA_PORT}
USE_PHP+=	ldap
.endif

.if defined(WITH_APACHE)
USE_APACHE=	20+
.endif

.if defined(WITH_INSTALLGD)
USE_PHP+=	pdf gd
.endif

post-extract:
	${INSTALL_SCRIPT} ${FILESDIR}/setup.sh ${WRKSRC}/

post-install:
	@${CAT} ${PKGMESSAGE}

setup:
	@cd ${WRKSRC}; ${WRKSRC}/setup.sh

.include <bsd.port.post.mk>
