# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=		radicale
PORTVERSION=		0.8
PORTREVISION=		1
CATEGORIES=		www python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		Radicale-${PORTVERSION}

MAINTAINER=		feld@FreeBSD.org
COMMENT=		Python based CalDAV/CardDAV server

LICENSE=		GPLv3

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Radicale

USERS=			radicale
GROUPS=			radicale
USE_RC_SUBR=		radicale
SUB_LIST+=		USERS="${USERS}"

OPTIONS_DEFINE=		HTTP LDAP
HTTP_DESC=		HTTP authentication support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTTP}
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}requests1>=0:${PORTSDIR}/www/py-requests1
USE_PYTHON=		2
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}ldap2>=0:${PORTSDIR}/net/py-ldap2
USE_PYTHON=		2
.endif

post-patch:
	${REINPLACE_CMD} 's,= /etc,= ${PREFIX}/etc,g' ${WRKSRC}/config
	${REINPLACE_CMD} 's,~/.config/radicale,${DATADIR},g' ${WRKSRC}/config

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}/${ETCDIR}/config.sample
	${INSTALL_DATA} ${WRKSRC}/logging ${STAGEDIR}/${ETCDIR}/logging.sample

.include <bsd.port.mk>
