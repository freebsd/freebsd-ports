# New ports collection makefile for:	DarwinStreamingServer
# Date created:				2002/02/23
# Whom:					steve@stevenwills.com
#
# $FreeBSD$
#

PORTNAME=	DarwinStreamingServer
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	#http://developer.apple.com/darwin/projects/streaming/source/
#		You must accept APSL (Apple Public Source License),  and get
#		DarwinStreamingSrc5.0.zip.
DISTNAME=	DarwinStreamingSrc${PORTVERSION}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Darwin Streaming Server, a MP3, MPEG4 and QuickTime streaming server

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay

RESTRICTED=	"See http://www.opensource.apple.com/apsl/"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		${RESTRICTED}
.endif

USE_ZIP=	YES
USE_REINPLACE=	YES

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
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/WebAdminHtml/adminprotocol-lib.pl
	@${REINPLACE_CMD} -e 's,${PREFIX}/sbin/StreamingServerModules,${PREFIX}/libexec/StreamingServerModules,' \
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/streamingserver.xml-POSIX
	@${REINPLACE_CMD} -e 's,${PREFIX}/movies,${DATADIR}/movies,' \
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/WebAdminHtml/adminprotocol-lib.pl
	@${REINPLACE_CMD} -e 's,/etc/streaming,${PREFIX}/etc/streaming,' \
		${WRKSRC}/qtaccess							\
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
	@${REINPLACE_CMD} -e 's,/var/streaming/logs,/var/log/streaming,' \
		${WRKSRC}/defaultPaths.h						\
		${WRKSRC}/streamingserver.xml-POSIX					\
		${WRKSRC}/WebAdmin/src/streamingadminserver.pl				\
		${WRKSRC}/WebAdmin/streamingadminserver_Darwin.conf
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
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./DSS_MakeRoot -f ${OPSYS} dss)

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
