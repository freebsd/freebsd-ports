# Created by: @BABOLO <.@babolo.ru>
# $FreeBSD$

PORTNAME=	flow-tools
PORTVERSION=	0.68.5.1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-ng

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Suite of tools and library to work with netflow data

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	MYSQL OPENSSL PGSQL
PGSQL_CONFIGURE_OFF=	--without-postgresql
PGSQL_CONFIGURE_ON=	--with-postgresql
PGSQL_USE=		PGSQL=yes
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_CONFIGURE_ON=	--with-mysql="${PREFIX}"
MYSQL_USE=		MYSQL=yes
OPENSSL_CONFIGURE_OFF=	--without-openssl
OPENSSL_CONFIGURE_ON=	--with-openssl="${OPENSSLBASE}"
OPENSSL_USE=		OPENSSL=yes

CONFLICTS=	flow-tools-[0-9]*

USES=		gmake tar:bzip2
USE_PYTHON_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir="${PREFIX}"
USE_LDCONFIG=	Yes

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	FLOW_CAPTURE_SPOOL="${FLOW_CAPTURE_SPOOL}" \
		FLOW_CAPTURE_USER="${FLOW_CAPTURE_USER}" \
		FLOW_CAPTURE_GROUP="${FLOW_CAPTURE_GROUP}" \
		FLOW_CAPTURE_UID="${FLOW_CAPTURE_UID}" \
		FLOW_CAPTURE_GID="${FLOW_CAPTURE_GID}" \
		FLOW_CAPTURE_PIDDIR="${FLOW_CAPTURE_PIDDIR}"
USE_RC_SUBR=	flow_capture flow_fanout

VARDIR?=		/var
FLOW_CAPTURE_SPOOL=	${VARDIR}/db/flows
FLOW_CAPTURE_USER=	flowtools
FLOW_CAPTURE_GROUP=	flowtools
FLOW_CAPTURE_UID=	174
FLOW_CAPTURE_GID=	174
FLOW_CAPTURE_PIDDIR=	${VARDIR}/run/flow-capture

post-patch:
	@${REINPLACE_CMD}\
	 -e 's|@sysconfdir@/sym/|${PREFIX}/share/flow-tools/|' \
	 -e 's|@sysconfdir@/cfg/|${PREFIX}/etc/flow-tools/|' \
	  ${WRKSRC}/docs/flow-*.1.in ${WRKSRC}/docs/flow-*.html.in
	@${REINPLACE_CMD} -e 's|!/bin/env|!/usr/bin/env|' \
		${WRKSRC}/bin/* ${WRKSRC}/utils/*

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libft.so.0

.include <bsd.port.mk>
