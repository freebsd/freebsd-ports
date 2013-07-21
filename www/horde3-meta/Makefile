# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	meta
PORTVERSION=	1.0
PORTREVISION=	12
CATEGORIES=	www
MASTER_SITES=	# Empty
DISTFILES=	# None

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Meta port for the horde framework

NO_BUILD=	yes
LHORDEDIR?=	www/horde

OPTIONS_DEFINE=	ANSEL CHORA DIMP GOLLEM HPASSWD IMP INGO JETA \
		KRONOLITH MIMP MNEMO NAG NIC TREAN TURBA VACATION \
		WHUPS KLUTZ
ANSEL_DESC=	Photo Gallery
CHORA_DESC=	CVS Web Viewer
DIMP_DESC=	Dynamic Imp
GOLLEM_DESC=	Web-Based File Manager
HERMES_DESC=	Time Tracking Application
HPASSWD_DESC=	Password Changing Module
IMP_DESC=	IMAP Webmail System
INGO_DESC=	Email-Filter Management
JETA_DESC=	Java SSH Applets
KRONOLITH_DESC=	Calendar Application
MIMP_DESC=	Mobile Webmail System
MNEMO_DESC=	Notes and Memo Application
NAG_DESC=	Task List Manager
NIC_DESC=	Network Monitor
TREAN_DESC=	Bookmark Manager
TURBA_DESC=	Contact Management
VACATION_DESC=	Vacation & Auto Respond
WHUPS_DESC=	Bug Tracking/Ticket System
KLUTZ_DESC=	Comic Strip Viewer

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/base/rpc.php:${PORTSDIR}/www/horde3-base

.if ${PORT_OPTIONS:MIMP}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/imp/index.php:${PORTSDIR}/mail/horde3-imp
.endif

.if ${PORT_OPTIONS:MMIMP}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/mimp/index.php:${PORTSDIR}/mail/horde3-mimp
.endif

.if ${PORT_OPTIONS:MDIMP}
RUN_DEPENDS+= ${LOCALBASE}/${LHORDEDIR}/dimp/compose.php:${PORTSDIR}/mail/horde3-dimp
.endif

.if ${PORT_OPTIONS:MINGO}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/ingo/filters.php:${PORTSDIR}/mail/horde3-ingo
.endif

.if ${PORT_OPTIONS:MTURBA}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/turba/minisearch.php:${PORTSDIR}/mail/horde3-turba
.endif

.if ${PORT_OPTIONS:MKRONOLITH}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/kronolith/index.php:${PORTSDIR}/deskutils/horde3-kronolith
.endif

.if ${PORT_OPTIONS:MMNEMO}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/mnemo/index.php:${PORTSDIR}/deskutils/horde3-mnemo
.endif

.if ${PORT_OPTIONS:MNAG}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/nag/data.php:${PORTSDIR}/deskutils/horde3-nag
.endif

.if ${PORT_OPTIONS:MCHORA}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/chora/index.php:${PORTSDIR}/devel/horde3-chora
.endif

.if ${PORT_OPTIONS:MGOLLEM}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/gollem/index.php:${PORTSDIR}/ftp/horde3-gollem
.endif

.if ${PORT_OPTIONS:MJETA}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/jeta/index.php:${PORTSDIR}/security/horde3-jeta
.endif

.if ${PORT_OPTIONS:MHPASSWD}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/passwd/index.php:${PORTSDIR}/www/horde3-passwd
.endif

.if ${PORT_OPTIONS:MVACATION}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/vacation/main.php:${PORTSDIR}/mail/horde3-vacation
.endif

.if ${PORT_OPTIONS:MTREAN}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/trean/data.php:${PORTSDIR}/www/horde3-trean
.endif

.if ${PORT_OPTIONS:MNIC}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/nic/status.php:${PORTSDIR}/net-mgmt/horde3-nic
.endif

.if ${PORT_OPTIONS:MANSEL}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/ansel/gallery.php:${PORTSDIR}/www/horde3-ansel
.endif

.if ${PORT_OPTIONS:MWHUPS}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/whups/index.php:${PORTSDIR}/devel/horde3-whups
.endif

.if ${PORT_OPTIONS:MHERMES}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/hermes/index.php:${PORTSDIR}/deskutils/horde3-hermes
.endif

.if ${PORT_OPTIONS:MKLUTZ}
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/klutz/index.php:${PORTSDIR}/deskutils/horde3-klutz
.endif

post-configure:
	@${CAT} ${FILESDIR}/post-configure-message

do-install:
	@${DO_NADA}

.include <bsd.port.post.mk>
