PORTNAME=	cbsd
DISTVERSION=	14.3.1
CATEGORIES=	sysutils

MAINTAINER=	fbsd-ports@convectix.com
COMMENT=	Yet another FreeBSD Jail, XEN and Bhyve Management Utility
WWW=		https://github.com/cbsd/cbsd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libssh2.so:security/libssh2
RUN_DEPENDS=	curl:ftp/curl \
		jq:textproc/jq \
		rsync:net/rsync \
		sudo:security/sudo

USES=		compiler:c++11-lang libedit pkgconfig:both sqlite
USE_GITHUB=	yes
USE_RC_SUBR=	cbsdd cbsdrsyncd cbsd-statsd-bhyve cbsd-statsd-hoster \
		cbsd-statsd-jail
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

CBSD_HOME?=	${PREFIX}/cbsd

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == x86_64
PLIST_SUB+=	X86=""
.else
PLIST_SUB+=	X86="@comment "
.endif

.if ${OPSYS} != FreeBSD
PLIST_SUB+=	FBSD="@comment "
LIB_DEPENDS+=	libelf.so:devel/libelf
.else
PLIST_SUB+=	FBSD=""
.endif

do-install:
	@${ECHO_MSG} "Installing in ${CBSD_HOME}"
	${CP} -a ${WRKSRC} ${STAGEDIR}${CBSD_HOME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cbsdsh/cbsd \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/misc/src/sipcalc/sipcalc \
		${STAGEDIR}${PREFIX}/cbsd/misc
	${INSTALL_PROGRAM} ${WRKSRC}/misc/src/cbsd_md5/cbsd_md5 \
		${STAGEDIR}${PREFIX}/cbsd/misc
	${RM} -r ${STAGEDIR}${PREFIX}/cbsd/bin/cbsdsh \
		${STAGEDIR}${PREFIX}/cbsd/bin/src \
		${STAGEDIR}${PREFIX}/cbsd/lib \
		${STAGEDIR}${PREFIX}/cbsd/misc/src \
		${STAGEDIR}${PREFIX}/cbsd/sbin/src \
		${STAGEDIR}${PREFIX}/cbsd/tools/src
	${RM} -rf ${STAGEDIR}${PREFIX}/cbsd/share/docs
	${INSTALL_MAN} ${WRKSRC}/man/cbsd.8 \
		${STAGEDIR}${PREFIX}/share/man/man8
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bsdconfig
	${RLN} ${STAGEDIR}${CBSD_HOME}/share/bsdconfig/cbsd \
		${STAGEDIR}${PREFIX}/libexec/bsdconfig/cbsd

.include <bsd.port.mk>
