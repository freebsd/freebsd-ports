# Created by: Patrick Gardella <patrick@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sash
PORTVERSION=	3.7
CATEGORIES=	shells
MASTER_SITES=	http://members.tip.net.au/~dbell/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Stand-Alone shell combining many common utilities

MAN1=		sash.1

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sash ${PREFIX}/bin/sash
	${INSTALL_MAN} ${WRKSRC}/sash.1 ${MAN1PREFIX}/man/man1/sash.1

post-install:
	@${ECHO_MSG} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/sash /etc/shells.bak; \
		${ECHO_CMD} ${PREFIX}/bin/sash) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
