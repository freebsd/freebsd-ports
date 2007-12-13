# New ports collection makefile for:	rsyslog-pgsql
# Date created:		13 December 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

COMMENT=	PostgreSQL output module for rsyslog
PKGNAMESUFFIX=	-pgsql

MASTERDIR=	${.CURDIR}/../rsyslog
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--enable-pgsql
RUN_DEPENDS=	rsyslog>=0:${PORTSDIR}/sysutils/rsyslog
PLIST_FILES=	lib/rsyslog/ompgsql.so
PLIST_DIRS=	lib/rsyslog
PLIST=	""

do-install:
	@${INSTALL} -d ${PREFIX}/lib/rsyslog/
	@${INSTALL_PROGRAM} ${WRKSRC}/plugins/ompgsql/.libs/ompgsql.so \
		${PREFIX}/lib/rsyslog/

.include "${MASTERDIR}/Makefile"
