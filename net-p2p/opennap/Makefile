# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opennap
PORTVERSION=	0.44
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	sam@cassiba.com
COMMENT=	Open-source Napster server

USES=		gmake
GNU_CONFIGURE=	YES
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

NO_STAGE=	yes
post-install:
	(${ECHO_CMD} "" ; ${ECHO_CMD} "admin" ; ${ECHO_CMD} "opennap" ; ${ECHO_CMD} "") | ${WRKSRC}/setup
.if defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Documentation skipped."
.else
	@${ECHO_MSG} "===> Installing documentation into ${PREFIX}/share/doc/opennap."
	@${MKDIR} ${PREFIX}/share/doc/opennap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/opennap
	${INSTALL_DATA} ${WRKSRC}/napster.txt ${PREFIX}/share/doc/opennap
.endif
	@${ECHO_MSG} "===> Installing example config files into ${PREFIX}/share/doc/opennap."
	@${MKDIR} ${PREFIX}/share/opennap/examples
	${CHOWN} -R nobody:nobody ${PREFIX}/share/opennap
	cd ${WRKSRC} ; for FILE in sample.*; do ${INSTALL_DATA} $${FILE} ${PREFIX}/share/opennap/examples ; done
	@${ECHO_MSG} "===> Installing startup script into ${PREFIX}/etc/rc.d."
	${INSTALL_SCRIPT} ${FILESDIR}/opennap.sh ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
