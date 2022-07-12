PORTNAME=	cbsd
DISTVERSION=	13.1.2
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	Yet another FreeBSD Jail, XEN and Bhyve Management Utility

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libssh2.so:security/libssh2
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		rsync:net/rsync \
		sqlite3:databases/sqlite3 \
		sudo:security/sudo

USES=		compiler:c++11-lang libedit pkgconfig:both
USE_GITHUB=	yes
USE_RC_SUBR=	cbsdd cbsdrsyncd cbsd-statsd-bhyve cbsd-statsd-hoster \
		cbsd-statsd-jail
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-deinstall pkg-message

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

CBSD_HOME?=	${PREFIX}/cbsd

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == x86_64
PLIST_SUB=	X86=""
.else
PLIST_SUB=	X86="@comment "
.endif

.if ${OPSYS} != FreeBSD
PLIST_SUB+=	FBSD="@comment "
LIB_DEPENDS+=	libelf.so:devel/libelf
RUN_DEPENDS+=	sysrc:sysutils/sysrc
.else
PLIST_SUB+=	FBSD=""
.endif

do-install:
	@${ECHO} "Installing in ${CBSD_HOME}"
	${MKDIR} ${STAGEDIR}${CBSD_HOME}
	${CP} -a ${WRKSRC}/ ${STAGEDIR}${CBSD_HOME}
	${INSTALL_PROGRAM} -s ${WRKSRC}/bin/cbsdsh/cbsd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} -s ${WRKSRC}/misc/src/sipcalc/sipcalc \
		${STAGEDIR}${PREFIX}/cbsd/misc/sipcalc
	${RM} -rf ${STAGEDIR}${PREFIX}/cbsd/bin/cbsdsh \
		${STAGEDIR}${PREFIX}/cbsd/bin/src \
		${STAGEDIR}${PREFIX}/cbsd/lib \
		${STAGEDIR}${PREFIX}/cbsd/misc/src \
		${STAGEDIR}${PREFIX}/cbsd/sbin/src \
		${STAGEDIR}${PREFIX}/cbsd/tools/src
	${INSTALL_MAN} ${WRKSRC}/man/cbsd.8 ${STAGEDIR}${PREFIX}/man/man8/cbsd.8

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bsdconfig
	@${LN} -sf ${CBSD_HOME}/share/bsdconfig/cbsd ${STAGEDIR}${PREFIX}/libexec/bsdconfig/cbsd

.include <bsd.port.mk>
