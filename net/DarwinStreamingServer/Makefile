# New ports collection makefile for:	DarwinStreamingServer
# Date created:				2002/02/23
# Whom:					steve@stevenwills.com
#
# $FreeBSD$
#

PORTNAME=	DarwinStreamingServer
PORTVERSION=	6.0.3
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://dss.macosforge.org/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     nork
DISTNAME=	DarwinStreamingSrvr${PORTVERSION}-Source
EXTRACT_SUFX=	.tar

PATCH_SITES=	http://www.abrahamsson.com/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=nork
PATCHFILES=	dss-6.0.3.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Darwin Streaming Server, a MP3, MPEG4, and QuickTime streaming server

RUN_DEPENDS=	p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay

NOT_FOR_ARCHS=	ia64 powerpc sparc64

USE_PERL5_RUN=	yes
USE_PERL5_BUILD=yes
USE_RC_SUBR=	streamingadminserver.sh darwin_streaming_server.sh
SUB_LIST+=	PERL=${PERL}

PKGMESSAGE=	${WRKDIR}/pkg-message

MAKE_ENV+=	MAKE="${MAKE}"				\
		DATADIR="${DATADIR}"			\
		PTHREAD_LIBS="${PTHREAD_LIBS}"		\
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -rf \
		${WRKSRC}/dssPackageMetaData \
		${WRKSRC}/pubPackageMetaData \
		${WRKSRC}/qtssPackageMetaData \
		${WRKSRC}/WebAdmin/NetSSLeay

post-patch:
	@${REINPLACE_CMD} -e 's,/var/streaming/logs,/var/log/streaming,' \
		${WRKSRC}/Install							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming/playlists,/var/spool/streaming.playlists,' \
		${WRKSRC}/Install							\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf

	@${REINPLACE_CMD} -e 's,/usr/local/movies,${DATADIR}/movies,' \
		${WRKSRC}/Install							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/WebAdminHtml/adminprotocol-lib.pl
	@${REINPLACE_CMD} -e 's,/usr/local/sbin/StreamingServerModules,/usr/local/libexec/StreamingServerModules,' \
		${WRKSRC}/Install							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX
	@${REINPLACE_CMD} -e 's,/etc/streaming,/usr/local/etc/streaming,' \
		${WRKSRC}/Install							\
		${WRKSRC}/qtaccess							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/StreamingProxy.tproj/StreamingProxy.html			\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming,${DATADIR},' \
		${WRKSRC}/Install							\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf

	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/Install							\
		${WRKSRC}/qtaccess							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/Documentation/readme.txt					\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/StreamingProxy.tproj/StreamingProxy.html			\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf			\
		${WRKSRC}/WebAdmin/WebAdminHtml/adminprotocol-lib.pl

	@${REINPLACE_CMD} -e '/-O[23]/d' \
		${WRKSRC}/Makefile.POSIX						\
		${WRKSRC}/QTFileLib/Makefile.POSIX					\
		${WRKSRC}/qtpasswd.tproj/Makefile.POSIX					\
		${WRKSRC}/MP3Broadcaster/Makefile.POSIX					\
		${WRKSRC}/HTTPUtilitiesLib/Makefile.POSIX				\
		${WRKSRC}/StreamingLoadTool/Makefile.POSIX				\
		${WRKSRC}/CommonUtilitiesLib/Makefile.POSIX				\
		${WRKSRC}/StreamingProxy.tproj/Makefile.POSIX				\
		${WRKSRC}/PlaylistBroadcaster.tproj/Makefile.POSIX			\
		${WRKSRC}/QTFileTools/QTRTPGen.tproj/Makefile.POSIX			\
		${WRKSRC}/QTFileTools/QTSDPGen.tproj/Makefile.POSIX			\
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
		${WRKSRC}/APIModules/QTSSDemoRedirectModule.bproj/Makefile.POSIX	\
		${WRKSRC}/APIModules/QTSSDemoAuthorizationModule.bproj/Makefile.POSIX

do-build:
	# XXX: Quick hack after ddss-6.0.3.patch is patched.
	# I don't know why these files are removed.
	# ${LN} -s RTSPRequest3GPP.cpp.orig ${WRKSRC}/Server.tproj/RTSPRequest3GPP.cpp
	# ${LN} -s RTPStream.h.orig ${WRKSRC}/Server.tproj/RTPStream.h
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} sh -x ./Buildit)

post-build:
	@${CP} ${.CURDIR}/pkg-message ${WRKDIR}/pkg-message
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKDIR}/pkg-message
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} /bin/sh -x ./DSS_MakeRoot -f ${OPSYS})

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	@(cd ${WRKSRC}/${OPSYS}; ${SETENV} ${MAKE_ENV} ./Install)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
