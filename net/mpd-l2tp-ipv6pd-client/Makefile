# New ports collection makefile for:	mpd-l2tp-ipv6pd-client
# Date created:				Nov 2 2006
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpd-l2tp-ipv6pd-client
PORTVERSION=	20080101
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ume@FreeBSD.org
COMMENT=	A sample implementaiton set of "L2TP-IPv6PD" client using mpd

BUILD_DEPENDS=	${MPD_NAME}:${PORTSDIR}/net/${MPD_NAME}
RUN_DEPENDS=	dhcp6ctl:${PORTSDIR}/net/dhcp6 \
		${MPD_NAME}:${PORTSDIR}/net/${MPD_NAME}

MANUAL_PACKAGE_BUILD=yes
NO_PACKAGE=	yes
USE_RC_SUBR=	yes

CONF_DIR?=	etc/${MPD_NAME}
CONF_FILES=	dhcp6c.conf.in mpd.conf mpd.links rtadvd.conf
SCRIPT_FILES=	dhcp6c_pd.sh linkdown.sh linkup.sh
SECRET_FILES=	mpd.secret

SCRIPTS_ENV=	WRKDIR="${WRKDIR}" \
		SCRIPTDIR="${SCRIPTDIR}" \
		PREFIX="${PREFIX}" \
		CONF_DIR="${CONF_DIR}" \
		MPD_NAME="${MPD_NAME}" \
		RC_SUBR="${RC_SUBR}" \
		CAT="${CAT}" \
		CP="${CP}" \
		DIALOG="${DIALOG}" \
		MD5="${MD5}" \
		MKTEMP="${MKTEMP}" \
		RM="${RM}" \
		SED="${SED}" \
		WHICH="${WHICH}"

PLIST_SUB=	CONF_DIR="${CONF_DIR}" \
		MPD_NAME="${MPD_NAME}"

PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(WITH_MPD5)
MPD_NAME=	mpd5
.else
MPD_NAME=	mpd4
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602106 || (${OSVERSION} >= 700000 && ${OSVERSION} < 700031)
IGNORE=		does not work with old ng_ksocket
.endif

do-build:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/setting
	@${DIALOG} --clear

do-install:
	@if [ -f ${PREFIX}/${CONF_DIR}/mpd.conf -o \
	      -f ${PREFIX}/${CONF_DIR}/mpd.links -o \
	      -f ${PREFIX}/${CONF_DIR}/mpd.secret ]; then \
		${ECHO_CMD} "There are ${MPD_NAME} configuration files already"; \
		${ECHO_CMD} "Pleae remove at least following files before install:"; \
		${ECHO_CMD} "    ${PREFIX}/${CONF_DIR}/mpd.conf"; \
		${ECHO_CMD} "    ${PREFIX}/${CONF_DIR}/mpd.links"; \
		${ECHO_CMD} "    ${PREFIX}/${CONF_DIR}/mpd.secret"; \
		exit 1; \
	fi
	@${MKDIR} ${PREFIX}/${CONF_DIR}
.for f in ${CONF_FILES}
	@${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${CONF_DIR}/${f}
.endfor
	@${INSTALL_DATA} ${WRKDIR}/mpd ${PREFIX}/${CONF_DIR}/${MPD_NAME}
.for f in ${SCRIPT_FILES}
	@${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/${CONF_DIR}/${f}
.endfor
.for f in ${SECRET_FILES}
	@${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m 400 \
	    ${WRKDIR}/${f} ${PREFIX}/${CONF_DIR}/${f}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
