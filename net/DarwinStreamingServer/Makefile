# New ports collection makefile for:	DarwinStreamingServer
# Date created:				2002/02/23
# Whom:					steve@stevenwills.com
#
# $FreeBSD$
#

PORTNAME=	DarwinStreamingServer
PORTVERSION=	4.1.1
CATEGORIES=	net
MASTER_SITES=	#http://developer.apple.com/darwin/projects/streaming/source/
#		You must accept APSL (Apple Public Source License),  and get
#		DSS-4_1_1.src.tar.gz.
DISTNAME=	DSS-4_1_1.src

MAINTAINER=	nork@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay

RESTRICTED=	"See http://www.opensource.apple.com/apsl/"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		${RESTRICTED}
.endif

USE_REINPLACE=	YES

PKGMESSAGE=	${WRKDIR}/pkg-message

MAKE_ENV+=	CC="${CC}"				\
		CXX="${CXX}"				\
		MAKE="${MAKE}"				\
		DATADIR="${DATADIR}"			\
		PTHREAD_LIBS="${PTHREAD_LIBS}"		\
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\

pre-fetch:
	@[ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ] || ( \
	${ECHO} "********************************************************************";	\
	${ECHO} "Please get ${DISTNAME}${EXTRACT_SUFX} from";				\
	${ECHO} "	http://developer.apple.com/darwin/projects/streaming/source/";	\
	${ECHO} "And, you must accept APSL (Apple Public Source License).";		\
	${ECHO} "********************************************************************";	\
	${FALSE}                                                                        \
	)

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,' \
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/Server.tproj/QTSServerPrefs.cpp				\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/StreamingProxy.tproj/StreamingProxy.html			\
		${WRKSRC}/WebAdmin/WebAdminHtml/adminprotocol-lib.pl
	@${REINPLACE_CMD} -e 's,${PREFIX}/sbin/StreamingServerModules,${PREFIX}/libexec/StreamingServerModules,' \
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/Server.tproj/QTSServerPrefs.cpp
	@${REINPLACE_CMD} -e 's,${PREFIX}/movies,${DATADIR}/movies,' \
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/Server.tproj/QTSServerPrefs.cpp				\
		${WRKSRC}/WebAdmin/WebAdminHtml/adminprotocol-lib.pl
	@${REINPLACE_CMD} -e 's,/etc/streaming,${PREFIX}/etc/streaming,' \
		${WRKSRC}/qtaccess							\
		${WRKSRC}/Server.tproj/main.cpp						\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/Documentation/DevNotes.html					\
		${WRKSRC}/qtpasswd.tproj/QTSSPasswd.cpp					\
		${WRKSRC}/MP3Broadcaster/MP3Broadcaster.cpp				\
		${WRKSRC}/StreamingProxy.tproj/proxy_unix.c				\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/StreamingProxy.tproj/StreamingProxy.html			\
		${WRKSRC}/APIModules/QTSSAccessModule/QTSSAccessModule.cpp		\
		${WRKSRC}/APIModules/QTSSReflectorModule/QTSSRelayModule.cpp		\
		${WRKSRC}/APIModules/QTSSDemoAuthorizationModule.bproj/QTSSDemoModule.cpp
	@${REINPLACE_CMD} -e 's,/var/streaming/broadcast_sdpfiles,/var/run/streaming.broadcast_sdpfiles,' \
		${WRKSRC}/Server.tproj/SDPTimeoutTask.cpp
	@${REINPLACE_CMD} -e 's,/var/streaming/logs,/var/log/streaming,' \
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/Server.tproj/QTSServerPrefs.cpp				\
		${WRKSRC}/Server.tproj/RTPPacketResender.cpp				\
		${WRKSRC}/Server.tproj/RTPSessionInterface.cpp				\
		${WRKSRC}/APIModules/QTSSHttpFileModule/QTSSHttpFileModule.cpp		\
		${WRKSRC}/APIModules/QTSSAccessLogModule/QTSSAccessLogModule.cpp	\
		${WRKSRC}/APIModules/QTSSMP3StreamingModule/QTSSMP3StreamingModule.cpp
	@${REINPLACE_CMD} -e 's,/var/streaming/AdminHtml,${DATADIR}/AdminHtml,' \
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming/playlists,/var/spool/streaming.playlists,' \
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming/streamingadminserver.pid,/var/run/streamingadminserver.pid,' \
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Buildit)

post-build:
	@${CP} ${.CURDIR}/pkg-message ${WRKDIR}/pkg-message
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKDIR}/pkg-message

pre-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./DSS_MakeRoot -f ${OPSYS})

do-install:
	@(cd ${WRKSRC}/${OPSYS}; ${SETENV} ${MAKE_ENV} ./Install)

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/streamingadminserver.sh    ${PREFIX}/etc/rc.d/
	${INSTALL_SCRIPT} ${FILESDIR}/darwin_streaming_server.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
