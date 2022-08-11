PORTNAME=	gopher
PORTVERSION=	3.0.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://gopher.quux.org:70/give-me-gopher/ \
		http://aaron.baugher.biz/files/FreeBSD/ports/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	aaron@baugher.biz
COMMENT=	Gopher client for access to a distributed document service

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's,<malloc.h>,<stdlib.h>,'
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gopher/gopher ${STAGEDIR}${PREFIX}/bin/gopher
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gopher
	${INSTALL_DATA} ${WRKSRC}/gopher/gopher.rc ${STAGEDIR}${PREFIX}/etc/gopher/gopher.rc
	${INSTALL_DATA} ${WRKSRC}/gopher/gopherremote.rc ${STAGEDIR}${PREFIX}/etc/gopher/gopherremote.rc
	${INSTALL_DATA} ${WRKSRC}/gopher/gopher.hlp ${STAGEDIR}${PREFIX}/etc/gopher/gopher.hlp
	${INSTALL_PROGRAM} ${WRKSRC}/gophfilt/gophfilt ${STAGEDIR}${PREFIX}/bin/gophfilt
	${INSTALL_MAN} ${WRKSRC}/doc/gopher.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/gophfilt.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/gopherrc.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
