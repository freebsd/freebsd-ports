# $FreeBSD$

PORTNAME=	cbsd
PORTVERSION=	9.2.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bsdstore.ru/downloads/ \
		GH

MAINTAINER=	olevole@olevole.ru
COMMENT=	Yet another FreeBSD Jail Management Utility

LICENSE=	BSD

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		sudo:${PORTSDIR}/security/sudo \
		sqlite3:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS=	ssh2:${PORTSDIR}/security/libssh2

USE_GITHUB=	yes
GH_ACCOUNT=	olevole
GH_PROJECT=	cbsd
GH_COMMIT=	3e85b94

SUB_FILES=	pkg-message

CBSD_HOME?=	${PREFIX}/cbsd

MAN8=		cbsd.8

NO_STAGE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 901000
IGNORE=	does not work on FreeBSD < 9.1
.endif

.if ${OSVERSION} < 902001
RUN_DEPENDS+=	sysrc:${PORTSDIR}/sysutils/sysrc
.endif

post-install:
	@${FIND} -s ${CBSD_HOME} -not -type d | ${SORT} | \
	${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${CBSD_HOME} -type d | ${SORT} -r | \
	${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
