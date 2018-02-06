# Created by: @BABOLO <.@babolo.ru>
# $FreeBSD$

PORTNAME=	flow-tools
PORTVERSION=	0.68
PORTREVISION=	10
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Suite of tools and library to work with netflow data

PORTSCOUT=	skipv:0.411

OPTIONS_DEFINE=	MYSQL OPENSSL PGSQL

USES=		python:run shebangfix
SHEBANG_FILES=	bin/flow-*
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir="${PREFIX}"
MAKE_ARGS=	AM_CFLAGS="${CFLAGS}"

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

PGSQL_CONFIGURE_ON=	--with-pgsql="${LOCALBASE}"
PGSQL_USES=		pgsql
MYSQL_CONFIGURE_ON=	--with-mysql="${LOCALBASE}"
MYSQL_USES=		mysql
OPENSSL_CONFIGURE_ON=	--with-openssl="${OPENSSLBASE}"
OPENSSL_USES=		ssl

post-patch:
	${REINPLACE_CMD}\
	 -e 's|@localstatedir@/sym/|${PREFIX}/share/flow-tools/|' \
	 -e 's|@localstatedir@/cfg/|${PREFIX}/etc/flow-tools/|' \
	  ${WRKSRC}/docs/flow-*.1.in ${WRKSRC}/docs/flow-*.html.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
