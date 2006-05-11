# New ports collection makefile for:	DarwinStreamingServer
# Date created:				2002/02/23
# Whom:					steve@stevenwills.com
#
# $FreeBSD$
#

PORTNAME=	DarwinStreamingServer
PORTVERSION=	5.5
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	#http://developer.apple.com/darwin/projects/streaming/source/
#		You must accept APSL (Apple Public Source License),  and get
#		DarwinStreamingSrvr5.5-Source.tar.
DISTNAME=	DarwinStreamingSrvr${PORTVERSION}-Source
EXTRACT_SUFX=	.tar

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Darwin Streaming Server, a MP3, MPEG4 and QuickTime streaming server

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay

RESTRICTED=	"See http://www.opensource.apple.com/apsl/"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		${RESTRICTED}
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message

MAKE_ENV+=	CC="${CC}"				\
		CXX="${CXX}"				\
		MAKE="${MAKE}"				\
		DATADIR="${DATADIR}"			\
		PTHREAD_LIBS="${PTHREAD_LIBS}"		\
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\

post-extract:
	@${RM} -rf ${WRKSRC}/dssPackageMetaData ${WRKSRC}/pubPackageMetaData ${WRKSRC}/qtssPackageMetaData

pre-fetch:
	@[ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ] || ( \
	${ECHO} "********************************************************************";	\
	${ECHO} "Please get ${DISTNAME}${EXTRACT_SUFX} from";				\
	${ECHO} "	http://developer.apple.com/darwin/projects/streaming/";		\
	${ECHO} "And, you must accept APSL (Apple Public Source License).";		\
	${ECHO} "Then, put in ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.";			\
	${ECHO} "********************************************************************";	\
	${FALSE}                                                                        \
	)

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,' \
		${WRKSRC}/Install							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/WebAdminHtml/adminprotocol-lib.pl
	@${REINPLACE_CMD} -e 's,${PREFIX}/sbin/StreamingServerModules,${PREFIX}/libexec/StreamingServerModules,' \
		${WRKSRC}/Install							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX
	@${REINPLACE_CMD} -e 's,${PREFIX}/movies,${DATADIR}/movies,' \
		${WRKSRC}/Install							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/WebAdminHtml/adminprotocol-lib.pl
	@${REINPLACE_CMD} -e 's,/etc/streaming,${PREFIX}/etc/streaming,' \
		${WRKSRC}/Install							\
		${WRKSRC}/qtaccess							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming/logs,/var/log/streaming,' \
		${WRKSRC}/Install							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming/AdminHtml,${DATADIR}/AdminHtml,' \
		${WRKSRC}/Install							\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming/playlists,/var/spool/streaming.playlists,' \
		${WRKSRC}/Install							\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming/streamingadminserver.pid,/var/run/streamingadminserver.pid,' \
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl
	@${REINPLACE_CMD} -e '/-O[23]/d' \
		${WRKSRC}/Makefile.POSIX						\
		${WRKSRC}/QTFileLib/Makefile.POSIX					\
		${WRKSRC}/qtpasswd.tproj/Makefile.POSIX					\
		${WRKSRC}/MP3Broadcaster/Makefile.POSIX					\
		${WRKSRC}/HTTPUtilitiesLib/Makefile.POSIX				\
		${WRKSRC}/CommonUtilitiesLib/Makefile.POSIX				\
		${WRKSRC}/StreamingProxy.tproj/Makefile.POSIX				\
		${WRKSRC}/StreamingServer.xcode/project.pbxproj				\
		${WRKSRC}/PlaylistBroadcaster.tproj/Makefile.POSIX			\
		${WRKSRC}/QTFileTools/QTRTPGen.tproj/Makefile.POSIX			\
		${WRKSRC}/QTFileTools/QTSDPGen.tproj/Makefile.POSIX			\
		${WRKSRC}/StreamingServer.pbproject/project.pbxproj			\
		${WRKSRC}/QTFileTools/QTFileInfo.tproj/Makefile.POSIX			\
		${WRKSRC}/QTFileTools/QTFileTest.tproj/Makefile.POSIX			\
		${WRKSRC}/APIModules/QTSSRefMovieModule/Makefile.POSIX			\
		${WRKSRC}/QTFileTools/QTTrackInfo.tproj/Makefile.POSIX			\
		${WRKSRC}/QTFileTools/QTBroadcaster.tproj/Makefile.POSIX		\
		${WRKSRC}/QTFileTools/QTRTPFileTest.tproj/Makefile.POSIX		\
		${WRKSRC}/QTFileTools/QTSampleLister.tproj/Makefile.POSIX		\
		${WRKSRC}/APIModules/QTSSHomeDirectoryModule/Makefile.POSIX		\
		${WRKSRC}/APIModules/QTSSRawFileModule.bproj/Makefile.POSIX		\
		${WRKSRC}/APIModules/QTSSSpamDefenseModule.bproj/Makefile.POSIX		\
		${WRKSRC}/APIModules/QTSSDemoAuthorizationModule.bproj/Makefile.POSIX

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Buildit)

post-build:
	@${CP} ${.CURDIR}/pkg-message ${WRKDIR}/pkg-message
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKDIR}/pkg-message
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./DSS_MakeRoot -f ${OPSYS})

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	@(cd ${WRKSRC}/${OPSYS}; ${SETENV} ${MAKE_ENV} ./Install)

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/streamingadminserver.sh    ${PREFIX}/etc/rc.d/
	${INSTALL_SCRIPT} ${FILESDIR}/darwin_streaming_server.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
