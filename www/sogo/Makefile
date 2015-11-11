# Created by: Euan Thoms <euan@potensol.com>
# $FreeBSD$

PORTNAME=		sogo
PORTVERSION=		2.3.2
PORTREVISION=		2
CATEGORIES=		www gnustep
MASTER_SITES=		http://www.sogo.nu/files/downloads/SOGo/Sources/
DISTNAME=		SOGo-${PORTVERSION}

MAINTAINER=		euan@potensol.com
COMMENT=		Groupware server with a focus on scalability and open standards

LICENSE=		GPLv2

LIB_DEPENDS=		libmemcached.so:${PORTSDIR}/databases/libmemcached \
			libcurl.so:${PORTSDIR}/ftp/curl \
			libDOM.so:${PORTSDIR}/devel/sope

OPTIONS_DEFINE=		ACTIVESYNC
OPTIONS_SUB=		yes

ACTIVESYNC_DESC=	Enable support for ActiveSync protocol (Experimental)

ACTIVESYNC_LIB_DEPENDS=	libwbxml2.so:${PORTSDIR}/textproc/wbxml2

USERS=			sogod
GROUPS=			sogod

USES=			gnustep objc
USE_GNUSTEP=		base build
USE_LDCONFIG=		${GNUSTEP_LOCAL_LIBRARIES}/sogo

USE_RC_SUBR=		sogod

SUB_LIST+=		GNUSTEP_LOCAL_TOOLS=${GNUSTEP_LOCAL_TOOLS} \
			GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES}

CONFIGURE_ARGS=		--disable-debug --enable-strip

.include <bsd.port.options.mk>

post-patch:
	${GREP} -rlF '/etc/sogo' ${WRKSRC} \
		| ${XARGS} ${REINPLACE_CMD} 's#/etc/sogo#${PREFIX}/etc/sogo#g'

.if ${PORT_OPTIONS:MACTIVESYNC}
	@${REINPLACE_CMD} -e 's/Tools/Tools ActiveSync/' ${WRKSRC}/GNUmakefile
.endif

do-configure:
	cd ${WRKSRC} ; . ${GNUSTEP_MAKEFILES}/GNUstep.sh ; ./configure ${CONFIGURE_ARGS}

post-stage:
	${MKDIR} ${STAGEDIR}/var/spool/sogo
	${MKDIR} ${STAGEDIR}${ETCDIR}
	(cp ${WRKSRC}/Scripts/sogo.conf ${STAGEDIR}${ETCDIR}/sogo.conf.sample)
	(cp ${FILESDIR}/expire-autoreply.creds.sample ${STAGEDIR}${ETCDIR}/)
	(cp ${FILESDIR}/ealarms-notify.creds.sample ${STAGEDIR}${ETCDIR}/)
	(cp ${FILESDIR}/cron-ealarms-notify.sample ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/Admin/)
	(cp ${FILESDIR}/cron-expire-autoreply.sample ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/Admin/)

.include <bsd.port.mk>
