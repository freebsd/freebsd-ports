# Created by: Matt Emmerton <matt@gsicomp.on.ca>
# $FreeBSD$

PORTNAME=	sntop
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor status of network nodes using fping

RUN_DEPENDS=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping

GNU_CONFIGURE=	yes
PORTDOCS=	COPYING CREDITS ChangeLog INSTALL README TODO
EXAMPLES=	alarm.sh sntoprc.EXAMPLE
SUB_FILES=	pkg-message

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sntop
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for example in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${example} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
