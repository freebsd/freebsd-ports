# Ports collection makefile for:  turba
# Date created:			  Sat Nov 16, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	turba
PORTVERSION=	2.3.5
DISTVERSIONSUFFIX=
PORTREVISION=	1
CATEGORIES=	mail www

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Contact management application

USE_HORDE=	base
USE_PHP=	ldap
USE_GETTEXT=	yes

PORTDOCS=	README CHANGES CREDITS INSTALL LDAP RELEASE_NOTES TODO UPGRADING

pre-patch:
	@${REINPLACE_CMD} -e "s:/usr/bin/ldapadd:${LOCALBASE}/bin/ldapadd:"	\
		${WRKSRC}/scripts/ldap/addou.pl

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
