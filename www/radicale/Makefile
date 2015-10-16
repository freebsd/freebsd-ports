# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=		radicale
PORTVERSION=		1.0.1
PORTREVISION=		0
CATEGORIES=		www python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		Radicale-${PORTVERSION}

MAINTAINER=		feld@FreeBSD.org
COMMENT=		Python based CalDAV/CardDAV server

LICENSE=		GPLv3

USE_PYTHON=		autoplist distutils

NO_ARCH=	yes

USERS=			radicale
GROUPS=			radicale
USE_RC_SUBR=		radicale
SUB_LIST+=		USERS="${USERS}" PYTHON_CMD="${PYTHON_CMD}"

OPTIONS_DEFINE=		HTTP LDAP
HTTP_DESC=		HTTP authentication support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTTP} || ${PORT_OPTIONS:MLDAP}
USES+=		python:2
.else
USES+=		python
.endif

.if ${PORT_OPTIONS:MHTTP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}requests1>=0:${PORTSDIR}/www/py-requests1
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ldap>=0:${PORTSDIR}/net/py-ldap
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
