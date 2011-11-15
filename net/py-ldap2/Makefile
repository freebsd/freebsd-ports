# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldap2
PORTVERSION=	2.4.4
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ldap-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	An LDAP module for python, for OpenLDAP2

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1-modules>=0:${PORTSDIR}/devel/py-asn1-modules

USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	easy_install
USE_OPENLDAP=	yes
PYDISTUTILS_PKGNAME=	python-ldap
PYEASYINSTALL_ARCHDEP=	yes

REPLACE_ARGS=	-e 's,/opt/openldap-RE24/lib,${LOCALBASE}/lib,' \
		-e 's,/opt/openldap-RE24/include,${LOCALBASE}/include,'

.if defined(WITH_SASL)
WANT_OPENLDAP_SASL=	yes
REPLACE_ARGS+=	-e 's,/usr/include/sasl,${LOCALBASE}/include/sasl,'
CONFLICTS+=	openldap2[34]-client-2.*
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
