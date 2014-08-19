# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	forwards
PORTVERSION=	3.2.1
PORTREVISION=	4
CATEGORIES=	mail www
DIST_SUBDIR=	horde

MAINTAINER= ports@FreeBSD.org
COMMENT=	E-mail forward

DEPRECATED=	EOL in April 2012
EXPIRATION_DATE=	2014-08-20
#-----------------------------------------------------------------------
NO_STAGE=	yes
# You may define these options:
#
# - WITHOUT_LDAP	if you do not need OpenLDAP;
#
# - WITHOUT_FTP	disable FTP support;
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL

. if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
. endif

.if !defined(WITHOUT_FTP)
USE_PHP+=	ftp
.endif

USE_HORDE=	base pkg-message
USES=		gettext
PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES TODO

.include "${.CURDIR}/../../www/horde3-base/bsd.horde.mk"
.include <bsd.port.mk>
