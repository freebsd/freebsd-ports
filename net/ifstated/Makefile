# New ports collection makefile for: ifstated
# Date created:         18 November 2004
# Whom:                 Matthew George <mdg@secureworks.net>
#
# $FreeBSD$
#

PORTNAME=	ifstated
PORTVERSION=	20050505
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.secureworks.net/pub/ifstated/

MAINTAINER=	mdg@secureworks.net
COMMENT=	Interface State daemon

INSTALL_TARGET=	install install-man
MAN8=		ifstated.8

PLIST_FILES=	sbin/ifstated \
		etc/ifstated.conf etc/rc.d/ifstated.sh

PKGMESSAGE=	${WRKDIR}/pkg-message

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/ifstated.sh > ${WRKDIR}/ifstated.sh
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ifstated.c ${WRKSRC}/ifstated.8

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ifstated.sh ${PREFIX}/etc/rc.d/ifstated.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502113
IGNORE=		need link state change notification changes from May 2004
.endif

.include <bsd.port.post.mk>
