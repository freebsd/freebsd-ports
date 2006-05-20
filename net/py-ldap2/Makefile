# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldap2
PORTVERSION=	2.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-ldap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ldap-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	An LDAP module for python, for OpenLDAP2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_OPENLDAP=	yes

REPLACE_ARGS=	-e 's=/usr/local/openldap-REL_ENG_2_1/lib=${LOCALBASE}/lib=' \
		-e 's=/usr/local/openldap-REL_ENG_2_1/include=${LOCALBASE}/include='

.if defined(WITH_SASL)
WANT_OPENLDAP_SASL=	yes
REPLACE_ARGS+=	-e 's=/usr/local/cyrus-sasl/lib=${LOCALBASE}/lib/sasl2=' \
		-e 's=/usr/local/cyrus-sasl/include=${LOCALBASE}/include/sasl='
CONFLICTS+=	openldap2[23]-client-2.*
.else
REPLACE_ARGS+=	-e 's=ldap_r lber sasl2 ssl crypto=ldap_r lber ssl crypto='
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
