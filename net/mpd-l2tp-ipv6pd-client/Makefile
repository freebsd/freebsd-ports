# New ports collection makefile for:	mpd-l2tp-ipv6pd-client
# Date created:				Nov 2 2006
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpd-l2tp-ipv6pd-client
PORTVERSION=	20081105
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Sample implementation set of "L2TP-IPv6PD" client using mpd

IS_INTERACTIVE=	yes
MANUAL_PACKAGE_BUILD=yes
NO_PACKAGE=	yes
USE_RC_SUBR=	yes

OPTIONS_SINGLE=		MPD
OPTIONS_SINGLE_MPD=	MPD4 MPD5
OPTIONS_DEFAULT=	MPD5
MPD4_DESC=		Use mpd4
MPD5_DESC=		Use mpd5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPD4}
MPD_NAME=	mpd4
MPD4=		""
.else
MPD_NAME=	mpd5
MPD4=		"@comment "
.endif

BUILD_DEPENDS=	${MPD_NAME}:${PORTSDIR}/net/${MPD_NAME}
RUN_DEPENDS=	dhcp6ctl:${PORTSDIR}/net/dhcp6 \
		${MPD_NAME}:${PORTSDIR}/net/${MPD_NAME}

CONF_DIR?=	etc/${MPD_NAME}
MPD_CONF_FILES=	dhcp6c.conf.in rtadvd.conf
SCRIPT_FILES=	dhcp6c_pd.sh linkdown.sh linkup.sh
SECRET_FILES=	mpd.secret

SCRIPTS_ENV=	WRKDIR="${WRKDIR}" \
		SCRIPTDIR="${SCRIPTDIR}" \
		PREFIX="${PREFIX}" \
		CONF_DIR="${CONF_DIR}" \
		MPD_NAME="${MPD_NAME}" \
		CAT="${CAT}" \
		CP="${CP}" \
		DIALOG="${DIALOG}" \
		MD5="${MD5}" \
		MKTEMP="${MKTEMP}" \
		RM="${RM}" \
		SED="${SED}" \
		WHICH="${WHICH}"

PLIST_SUB=	CONF_DIR=${CONF_DIR} \
		MPD_NAME=${MPD_NAME} \
		MPD4=${MPD4}

PKGMESSAGE=	${WRKDIR}/pkg-message

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
.if ${PORT_OPTIONS:MMPD4}
	@${INSTALL_DATA} ${WRKDIR}/mpd.conf ${PREFIX}/${CONF_DIR}/mpd.conf
	@${INSTALL_DATA} ${WRKDIR}/mpd.links ${PREFIX}/${CONF_DIR}/mpd.links
.else
	@${INSTALL_DATA} ${WRKDIR}/mpd5.conf ${PREFIX}/${CONF_DIR}/mpd.conf
.endif
.for f in ${MPD_CONF_FILES}
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

.include <bsd.port.mk>
