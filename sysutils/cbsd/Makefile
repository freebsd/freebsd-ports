# $FreeBSD$

PORTNAME=	cbsd
DISTVERSION=	13.0.1
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	Yet another FreeBSD Jail, XEN and Bhyve Management Utility

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rsync:net/rsync \
		sudo:security/sudo \
		sqlite3:databases/sqlite3 \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
LIB_DEPENDS=	libssh2.so:security/libssh2 \
		libsqlite3.so:databases/sqlite3

USES=		compiler:c++11-lang libedit pkgconfig:both
USE_GITHUB=	yes
USE_RC_SUBR=	cbsdd cbsdrsyncd cbsd-statsd-bhyve cbsd-statsd-hoster cbsd-statsd-jail

SUB_FILES=	pkg-message pkg-deinstall

CBSD_HOME?=	${PREFIX}/cbsd

USERS=	${PORTNAME}
GROUPS=	${PORTNAME}

BIN_FILES=	\
		bin/cbsdsh/mknodes \
		bin/cbsdsh/mksyntax

.include <bsd.port.options.mk>

do-install:
	@${ECHO} "Installing in ${CBSD_HOME}"
	${MKDIR} ${STAGEDIR}${CBSD_HOME}
	${CP} -a ${WRKSRC}/ ${STAGEDIR}${CBSD_HOME}
.for i in ${BIN_FILES}
	${STRIP_CMD} ${STAGEDIR}${CBSD_HOME}/${i}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/cbsd.8 ${STAGEDIR}${PREFIX}/man/man8/cbsd.8
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cbsdsh/cbsd ${STAGEDIR}${PREFIX}/bin

post-install:
	${CAT} ${PKGDIR}/pkg-plist-chunk > ${TMPPLIST} ;
	@${FIND} -s ${STAGEDIR}${CBSD_HOME} -not -type d | ${SORT} | \
	${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bsdconfig
	@${LN} -sf ${CBSD_HOME}/share/bsdconfig/cbsd ${STAGEDIR}${PREFIX}/libexec/bsdconfig/cbsd

.include <bsd.port.mk>
