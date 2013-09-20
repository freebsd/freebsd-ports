# Created by: Thierry Thomas (<thierry@thomas.as>)
# $FreeBSD$

PORTNAME=	turba
PORTVERSION=	2.3.6
DISTVERSIONSUFFIX=
PORTREVISION=	1
CATEGORIES=	mail www

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Contact management application

USE_HORDE=	base
USE_PHP=	ldap
USES=		gettext

PORTDOCS=	README CHANGES CREDITS INSTALL LDAP RELEASE_NOTES TODO UPGRADING

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e "s:/usr/bin/ldapadd:${LOCALBASE}/bin/ldapadd:"	\
		${WRKSRC}/scripts/ldap/addou.pl

.include "${.CURDIR}/../../www/horde3-base/bsd.horde.mk"
.include <bsd.port.mk>
