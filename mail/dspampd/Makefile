# New ports collection makefile for:	mail/dspampd
# Date created:				21 July 2004
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	dspampd
PORTVERSION=	2.00.r2
CATEGORIES=	mail perl5
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/DspamPD/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/dspampd/sources/
DISTNAME=	dspampd-v2.00-rc2-with-patches-kurt-pinboard

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Transparent smtp proxy - scans mail through DSPAM and/or ClamAV

WRKSRC=		${WRKDIR}/dspampd-v2.00-rc2

USE_PERL5_RUN=	YES
USE_RC_SUBR=	YES

OPTIONS=	DSPAM "Use stable dspam as anti-spam module" off
OPTIONS+=	DSPAM_DEVEL "Use devel dspam as antispam module" on
OPTIONS+=	DSPAM_VIRT_USERS "Non-system users in dspam" off
OPTIONS+=	CLAMAV	"Use clamav as antivir module" off
OPTIONS+=	CLAMAV_DEVEL  "Use clamav as antivir module" on
#OPTIONS+=	TIME_HIRES "" on

NO_BUILD=	YES
#NO_INSTALL=	YES
USE_REINPLACE=	YES

CONF_DIR=	${PREFIX}/etc/dspampd

RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh

PORTDOCS=	INSTALL README

_VAR_DIR=	/var
ARCHIVE_DIR?=	${_VAR_DIR}/spool/dspampd-archive
PLIST_SUB+=	ARCHIVE_DIR=${ARCHIVE_DIR}

PLIST_FILES+=	etc/rc.d/dspampd${RC_SUFX}

SED_FILES=	dspampd INSTALL README
SED_SCRIPT=	-e "s,/etc/,${CONF_DIR}/,g" \
		-e "s,/usr/bin/,${LOCALBASE}/bin/,g" \
		-e "s,/var/spool/dspam-archive,${ARCHIVE_DIR},g" \
		-e "s,/usr/bin/perl,${PERL},g"

SED_CONF_SCRIPT=	-e "s,%%PREFIX%%,${PREFIX},g"
SED_CONF_SCRIPT+=	-e "s,%%ARCHIVE_DIR%%,${ARCHIVE_DIR},"
SED_CONF_SCRIPT+=	-e "s,%%CONF_DIR%%,${CONF_DIR},g"

.include <bsd.port.pre.mk>

# defaults for package building
.ifndef(WITH_DEVEL) && !defined(WITH_DSPAM_DEVEL) && \
	!defined(WITH_CLAMAV) && !defined(WITH_CLAMAV_DEVEL)
WITH_DSPAM_DEVEL=	on
WITH_CLAMAV_DEVEL=	on
.endif

.ifdef(WITH_DSPAM)
RUN_DEPENDS+=	dspam:${PORTSDIR}/mail/dspam
.endif

# for now dspamc exists only in -devel
.ifdef(WITH_DSPAM_DEVEL)
RUN_DEPENDS+=	dspamc:${PORTSDIR}/mail/dspam-devel
SED_CONF_SCRIPT+=	-e "s,%%DSPAM%%,dspam,"
.else
SED_CONF_SCRIPT+=	-e "/%%DSPAM%%/D"
.endif

.ifndef(WITH_DSPAM_VIRT_USERS)
EXTRA_PATCHES=	${FILESDIR}/lpatch-dspampd_system_users.diff
.endif

.ifdef(WITH_CLAMAV)
RUN_DEPENDS+=	${LOCALBASE}/etc/clamd.conf:${PORTSDIR}/security/clamav
.endif

.ifdef(WITH_CLAMAV_DEVEL)
RUN_DEPENDS+=	${LOCALBASE}/etc/clamd.conf:${PORTSDIR}/security/clamav-devel
.endif

.ifdef(WITH_CLAMAV) || defined(WITH_CLAMAV_DEVEL)
SED_CONF_SCRIPT+=	-e "s,%%CLAMAV%%,clamd,"
.else
SED_CONF_SCRIPT+=	-e "/%%CLAMAV%%/D"
.endif

pre-extract:
	@${ECHO_CMD}
	@${ECHO_CMD} "Define, if you need:"
	@${ECHO_CMD} "ARCHIVE_DIR=${ARCHIVE_DIR} (default ${_VAR_DIR}/spool/dspampd-archive)."
	@${ECHO_CMD}

pre-configure:
.if defined(WITH_DSPAM) && defined(WITH_DSPAM_DEVEL)
	@${ECHO_CMD}
	@${ECHO_CMD} "DSPAM and DSPAM_DEVEL are mutually exclusive."
	@${ECHO_CMD} "Do a \"make rmconfig\" and start over."
	@${ECHO_CMD}
	@${FALSE}
.endif
.if (defined(WITH_CLAMAV) && defined(WITH_CLAMAV_DEVEL))
	@${ECHO_CMD}
	@${ECHO_CMD} "CLAMAV and CLAMAV_DEVEL are mutually exclusive."
	@${ECHO_CMD} "Do a \"make rmconfig\" and start over."
	@${ECHO_CMD}
	@${FALSE}
.endif

post-patch:
.for _file in ${SED_FILES}
	@${REINPLACE_CMD} ${SED_SCRIPT} ${WRKSRC}/${_file}
.endfor
	@${CP} ${FILESDIR}/dspampd.rc ${WRKSRC}/dspampd.rc
	@${REINPLACE_CMD} ${SED_CONF_SCRIPT} ${WRKSRC}/dspampd.rc
	@${REINPLACE_CMD} ${SED_CONF_SCRIPT} ${WRKSRC}/dspampd.conf

do-install::
	@${INSTALL_SCRIPT}  ${WRKSRC}/dspampd ${PREFIX}/sbin/
	@${MKDIR} ${CONF_DIR}
.for _conf_file in dspampd.conf dspampd.applyto dspampd.relaycontrol
	@${CP} ${WRKSRC}/${_conf_file} ${WRKSRC}/${_conf_file}.sample
	@${INSTALL_DATA} ${WRKSRC}/${_conf_file}.sample ${CONF_DIR}/
.endfor
	@${INSTALL_SCRIPT} ${WRKSRC}/dspampd.rc ${RC_DIR}/dspampd${RC_SUFX}
	${MKDIR} ${ARCHIVE_DIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

do-build:
	${DO_NADA}

post-install:
	@${ECHO_CMD}
	@${ECHO_CMD} "------------------------------------------------------"
	@${ECHO_CMD} "Copy"
	@${ECHO_CMD} "${PREFIX}/etc/dspampd.conf.sample"
	@${ECHO_CMD} "to"
	@${ECHO_CMD} "${PREFIX}/etc/dspampd.conf"
	@${ECHO_CMD} "and edit it to your needs."
	@${ECHO_CMD} "Add dspampd_enable="YES" in /etc/rc.conf to start dspampd on boot"
	@${ECHO_CMD} "-------------------------------------------------------"
	@${ECHO_CMD}

.include <bsd.port.post.mk>
