# New ports collection makefile for:	rsyslog-mysql
# Date created:		13 December 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

COMMENT=	MySQL output module for rsyslog
PKGNAMESUFFIX=	-mysql

MASTERDIR=	${.CURDIR}/../rsyslog
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--enable-mysql
RUN_DEPENDS=	rsyslog>=0:${PORTSDIR}/sysutils/rsyslog
PLIST_FILES=	lib/rsyslog/ommysql.so
PLIST_DIRS=	lib/rsyslog
PLIST=	""

do-install:
	@${INSTALL} -d ${PREFIX}/lib/rsyslog/
	@${INSTALL_PROGRAM} ${WRKSRC}/plugins/ommysql/.libs/ommysql.so \
		${PREFIX}/lib/rsyslog/

.include "${MASTERDIR}/Makefile"
