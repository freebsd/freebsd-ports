# $FreeBSD$

PORTNAME=	cbsd
PORTVERSION=	10.0.7
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	Yet another FreeBSD Jail Management Utility

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		sudo:${PORTSDIR}/security/sudo \
		sqlite3:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	olevole
GH_COMMIT=	74d433e

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
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${CBSD_HOME}
	@${INSTALL_MAN} ${WRKSRC}/man/cbsd.8 ${STAGEDIR}${PREFIX}/man/man8/cbsd.8
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cbsdsh/cbsd ${STAGEDIR}${PREFIX}/bin

post-install:
	${CAT} ${PKGDIR}/pkg-plist-chunk > ${TMPPLIST} ;
	@${FIND} -s ${STAGEDIR}${CBSD_HOME} -not -type d | ${SORT} | \
	${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${CBSD_HOME} -type d | ${SORT} -r | \
	${SED} -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
