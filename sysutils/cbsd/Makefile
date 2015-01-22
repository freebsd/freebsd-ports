# $FreeBSD$

PORTNAME=	cbsd
PORTVERSION=	10.1.3
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	Yet another FreeBSD Jail Management Utility

ONLY_FOR_ARCHS= i386 amd64
ONLY_FOR_ARCHS_REASON=	Depends on SSE 4.1 instructions

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		sudo:${PORTSDIR}/security/sudo \
		sqlite3:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	olevole
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	9d99c8e

USE_RC_SUBR=	cbsdd cbsdrsyncd

SUB_FILES=	pkg-message
PLIST_FILES+=	man/man8/cbsd.8.gz

CBSD_HOME?=	${PREFIX}/cbsd

.include <bsd.port.pre.mk>

USERS=	${PORTNAME}
GROUPS=	${PORTNAME}

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
IGNORE=	does not support FreeBSD versions < 10.0
.endif

do-install:
	@${ECHO} "Installing in ${CBSD_HOME}"
	${MKDIR} ${STAGEDIR}${CBSD_HOME}
	${CP} -a ${WRKSRC}/ ${STAGEDIR}${CBSD_HOME}
	${INSTALL_MAN} ${WRKSRC}/man/cbsd.8 ${STAGEDIR}${PREFIX}/man/man8/cbsd.8
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cbsdsh/cbsd ${STAGEDIR}${PREFIX}/bin

post-install:
	${CAT} ${PKGDIR}/pkg-plist-chunk > ${TMPPLIST} ;
	@${FIND} -s ${STAGEDIR}${CBSD_HOME} -not -type d | ${SORT} | \
	${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bsdconfig
	@${LN} -sf ${CBSD_HOME}/share/bsdconfig/cbsd ${STAGEDIR}${PREFIX}/libexec/bsdconfig/cbsd

.include <bsd.port.post.mk>
