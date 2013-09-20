# Created by: Matt Emmerton <matt@gsicomp.on.ca>
# $FreeBSD$

PORTNAME=	sntop
PORTVERSION=	1.4.3
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor status of network nodes using fping

RUN_DEPENDS=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping

GNU_CONFIGURE=	yes
PORTDOCS=	COPYING CREDITS ChangeLog INSTALL README TODO
EXAMPLES=	alarm.sh sntoprc.EXAMPLE
SUB_FILES=	pkg-message

MAN1=		sntop.1

NO_STAGE=	yes
post-install:
	@${STRIP_CMD} ${PREFIX}/bin/sntop
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${EXAMPLESDIR}
.for example in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${example} ${EXAMPLESDIR}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
