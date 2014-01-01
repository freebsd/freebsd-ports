# $FreeBSD$

PORTNAME=	cbsd
PORTVERSION=	10.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bsdstore.ru/downloads/ \
		GH

MAINTAINER=	olevole@olevole.ru
COMMENT=	Yet another FreeBSD Jail Management Utility

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		sudo:${PORTSDIR}/security/sudo \
		sqlite3:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2

USE_GITHUB=	yes
GH_ACCOUNT=	olevole
GH_PROJECT=	cbsd
GH_COMMIT=	ff6e7ea

SUB_FILES=	pkg-message
PLIST_FILES+=	man/man8/cbsd.8.gz

CBSD_HOME?=	${PREFIX}/cbsd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 901000
IGNORE=	does not work on FreeBSD < 9.1
.endif

.if ${OSVERSION} < 902001
RUN_DEPENDS+=	sysrc:${PORTSDIR}/sysutils/sysrc
.endif

post-install:
	@${FIND} -s ${STAGEDIR}${CBSD_HOME} -not -type d | ${SORT} | \
	${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${CBSD_HOME} -type d | ${SORT} -r | \
	${SED} -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
