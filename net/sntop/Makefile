# New ports collection makefile for:	sntop
# Date created:		05 August 2000
# Whom:			Matt Emmerton <matt@gsicomp.on.ca>
#
# $FreeBSD$
#

PORTNAME=	sntop
PORTVERSION=	1.4.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Monitor status of network nodes using fping

RUN_DEPENDS=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping

GNU_CONFIGURE=	yes
PORTDOCS=	COPYING CREDITS ChangeLog INSTALL README TODO
EXAMPLES=	alarm.sh sntoprc.EXAMPLE
SUB_FILES=	pkg-message

MAN1=		sntop.1

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
