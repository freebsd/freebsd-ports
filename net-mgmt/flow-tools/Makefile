# Created by: @BABOLO <.@babolo.ru>
# $FreeBSD$

PORTNAME=	flow-tools
PORTVERSION=	0.68.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Suite of tools and library to work with netflow data

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man

USES=		autoreconf libtool:keepla python:run shebangfix

OPTIONS_DEFINE=	MYSQL OPENSSL PGSQL
PGSQL_CONFIGURE_ON=	--with-postgresql
PGSQL_USES=		pgsql
MYSQL_CONFIGURE_ON=	--with-mysql="${LOCALBASE}"
MYSQL_USES=		mysql
OPENSSL_CONFIGURE_ON=	--with-openssl="${OPENSSLBASE}"
OPENSSL_USES=		ssl

SHEBANG_FILES=	bin/flow-*
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	5u623l20
GH_TAGNAME=	6e7c849
SUB_LIST=	FLOW_CAPTURE_SPOOL="${FLOW_CAPTURE_SPOOL}" \
		FLOW_CAPTURE_PIDDIR="${FLOW_CAPTURE_PIDDIR}"
USE_RC_SUBR=	flow_capture flow_fanout

VARDIR?=		/var
FLOW_CAPTURE_SPOOL=	${VARDIR}/db/flows
FLOW_CAPTURE_PIDDIR=	${VARDIR}/run/flow-capture

USERS=		flowtools
GROUPS=		flowtools

.include <bsd.port.mk>
