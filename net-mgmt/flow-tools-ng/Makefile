# New ports collection makefile for:	flow-tools
# Date created:				2000 Jul 25
# Whom:					@BABOLO <.@babolo.ru>
#
# $FreeBSD$
#

PORTNAME=	flow-tools
PORTVERSION=	0.68.4.2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-ng

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Suite of tools and library to work with netflow data

CONFLICTS=	flow-tools-[0-9]*

USE_PYTHON_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir="${PREFIX}"
USE_BZIP2=	Yes
USE_GMAKE=	Yes
USE_LDCONFIG=	Yes

MAN1=	flow-capture.1 flow-cat.1 flow-dscan.1 flow-expire.1	\
	flow-export.1 flow-fanout.1 flow-filter.1 flow-gen.1	\
	flow-header.1 flow-import.1 flow-mask.1 flow-merge.1	\
	flow-nfilter.1 flow-print.1 flow-receive.1		\
	flow-report.1 flow-send.1 flow-split.1 flow-stat.1	\
	flow-tag.1 flow-tools.1	flow-tools-examples.1 		\
	flow-xlate.1 flow-rptfmt.1 flow-log2rrd.1 flow-rpt2rrd.1

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

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=--with-postgresql
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=--without-postgresql
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=--with-mysql="${PREFIX}"
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=--without-mysql
.endif

.if defined(WITH_OPENSSL)
USE_OPENSSL=	Yes
CONFIGURE_ARGS+=--with-openssl="${OPENSSLBASE}"
.else
CONFIGURE_ARGS+=--without-openssl
.endif

post-patch:
	@${REINPLACE_CMD}\
	 -e 's|@sysconfdir@/sym/|${PREFIX}/share/flow-tools/|' \
	 -e 's|@sysconfdir@/cfg/|${PREFIX}/etc/flow-tools/|' \
	  ${WRKSRC}/docs/flow-*.1.in ${WRKSRC}/docs/flow-*.html.in
	@${REINPLACE_CMD} -e 's|!/bin/env|!/usr/bin/env|' \
		${WRKSRC}/bin/* ${WRKSRC}/utils/*

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for I in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/${I} ${PREFIX}/man/man1/
.endfor
	@${SETENV} ${SCRIPTS_ENV} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
