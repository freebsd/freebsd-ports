# $FreeBSD$

PORTNAME=	cbsd
PORTVERSION=	9.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bsdstore.ru/downloads/ \
		GH

MAINTAINER=	olevole@olevole.ru
COMMENT=	Yet another FreeBSD Jail Management Utility

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		sudo:${PORTSDIR}/security/sudo \
		sqlite3:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS=	ssh2:${PORTSDIR}/security/libssh2

USE_GITHUB=	yes
GH_ACCOUNT=	olevole
GH_PROJECT=	cbsd
GH_COMMIT=	68e0f95

SUB_FILES=	pkg-message

CBSD_HOME?=	${PREFIX}/cbsd

MAN7=		cbsd.7

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 901000
IGNORE=	does not work on FreeBSD < 9.1
.endif

post-install:
	@${FIND} -s ${CBSD_HOME} -not -type d | ${SORT} | \
	${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${CBSD_HOME} -type d | ${SORT} -r | \
	${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
