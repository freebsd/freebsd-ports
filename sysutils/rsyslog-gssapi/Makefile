# New ports collection makefile for:	rsyslog-gssapi
# Date created:		31 December 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

TYPE=		gssapi
COMMENT=	GSS API output module for rsyslog
PKGNAMESUFFIX=	-${TYPE}

MASTERDIR=	${.CURDIR}/../rsyslog
CONFIGURE_ARGS+=	--enable-${TYPE}-krb5
RUN_DEPENDS=	rsyslog>=0:${PORTSDIR}/sysutils/rsyslog
PLIST_FILES=	lib/rsyslog/om${TYPE}.so
PLIST_DIRS=	lib/rsyslog
PLIST=	""

do-install:
	@${INSTALL} -d ${PREFIX}/lib/rsyslog/
	@${INSTALL_PROGRAM} ${WRKSRC}/plugins/om${TYPE}/.libs/om${TYPE}.so \
		${PREFIX}/lib/rsyslog/

.include "${MASTERDIR}/Makefile"
