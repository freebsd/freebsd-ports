# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldap2
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-ldap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ldap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An LDAP module for python, for OpenLDAP2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_OPENLDAP=	yes
USE_REINPLACE=	yes
WANT_OPENLDAP_VER=	22

REPLACE_ARGS=	-e 's=/opt/openldap-OPENLDAP_REL_ENG_2_2/include=${LOCALBASE}/include='

.if defined(WITH_SASL)
WANT_OPENLDAP_SASL=	yes
REPLACE_ARGS+=	-e 's=/usr/include/sasl=${LOCALBASE}/include/sasl=' \
		-e 's=/opt/openldap-OPENLDAP_REL_ENG_2_2/lib=${LOCALBASE}/lib ${LOCALBASE}/lib/sasl2='
CONFLICTS+=	openldap22-client-2.*
.else
REPLACE_ARGS+=	-e 's=ldap_r lber ssl crypto sasl2=ldap_r lber ssl crypto=' \
		-e 's=/opt/openldap-OPENLDAP_REL_ENG_2_2/lib=${LOCALBASE}/lib='
.endif

pre-everything::
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO}
	@${ECHO} "WITH_SASL                with (Cyrus) SASL2 support"
	@${ECHO}
	@${ECHO} "============================================================="
	@${ECHO}

do-configure:
	@${REINPLACE_CMD} ${REPLACE_ARGS} ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
