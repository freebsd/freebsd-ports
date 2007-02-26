# New ports collection makefile for:	horde
# Date created:		24 February 2007
# Whom:			beech@alaskaparadise.com
#
# $FreeBSD$
#

PORTNAME=	meta
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	# Empty
PKGNAMEPREFIX=	horde-
DISTFILES=	# None

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Meta port for the horde framework

NO_BUILD=	yes
LHORDEDIR?=	www/horde

OPTIONS=	IMP "IMAP Webmail System" on	\
		MIMP "Mobile Webmail System" off	\
		INGO "Email-Filter Management" on	\
		TURBA "Contact Management" on	\
		KRONOLITH "Calendar Application" off \
		MNEMO "Notes and Memo Application" off	\
		NAG "Task List Manager" on	\
		CHORA "CVS Web Viewer" off	\
		GOLLEM "Web-Based File Manager" off	\
		JETA "Java SSH Applets" off	\
		HPASSWD "Password Changing Module" off

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

.if !defined(WITHOUT_IMP)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/imp/index.php:${PORTSDIR}/mail/imp
.endif

.if defined(WITH_MIMP)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/mimp/index.php:${PORTSDIR}/mail/mimp
.endif

.if !defined(WITHOUT_INGO)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/ingo/filters.php:${PORTSDIR}/mail/ingo
.endif

.if !defined(WITHOUT_TURBA)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/turba/minisearch.php:${PORTSDIR}/mail/turba
.endif

.if defined(WITH_KRONOLITH)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/kronolith/index.php:${PORTSDIR}/deskutils/kronolith
.endif

.if defined(WITH_MNEMO)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/mnemo/index.php:${PORTSDIR}/deskutils/mnemo
.endif

.if !defined(WITHOUT_NAG)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/nag/data.php:${PORTSDIR}/deskutils/nag
.endif

.if defined(WITH_CHORA)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/chora/index.php:${PORTSDIR}/devel/chora
.endif

.if defined(WITH_GOLLEM)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/gollem/index.php:${PORTSDIR}/ftp/gollem
.endif

.if defined(WITH_JETA)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/jeta/index.php:${PORTSDIR}/security/jeta
.endif

.if defined(WITH_HPASSWD)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/passwd/index.php:${PORTSDIR}/www/horde-passwd
.endif

post-configure:
	@${CAT} ${FILESDIR}/post-configure-message

postinstall:

	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

do-install:

.include <bsd.port.post.mk>
