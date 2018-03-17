# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	radicale
PORTVERSION=	1.1.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Radicale-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python based CalDAV/CardDAV server

LICENSE=	GPLv3

USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

USERS=		radicale
GROUPS=		radicale
USE_RC_SUBR=	radicale
SUB_LIST=	USERS="${USERS}" PYTHON_CMD="${PYTHON_CMD}"

OPTIONS_DEFINE=	HTTP LDAP
HTTP_DESC=	HTTP authentication support

HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests1>=0:www/py-requests1@${FLAVOR}
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=0:net/py-ldap@${FLAVOR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTTP} || ${PORT_OPTIONS:MLDAP}
USES+=		python:2.7
.else
USES+=		python
.endif

post-patch:
	${REINPLACE_CMD} 's,= /etc,= ${PREFIX}/etc,g' ${WRKSRC}/config
	${REINPLACE_CMD} 's,~/.config/radicale,${DATADIR},g' ${WRKSRC}/config

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}/${ETCDIR}/config.sample
	${INSTALL_DATA} ${WRKSRC}/logging ${STAGEDIR}/${ETCDIR}/logging.sample

.include <bsd.port.mk>
