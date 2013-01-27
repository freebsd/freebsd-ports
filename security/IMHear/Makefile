# Created by: Nicolas Gieczewski
# $FreeBSD$

PORTNAME=	IMHear
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://repository.nixsoftware.com/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An MSN Messenger event/message sniffer

DEPRECATED=	No more upstream, no more public distfiles
EXPIRATION_DATE=	2013-02-27

PKGMESSAGE=	${WRKDIR}/pkg-message
NO_INSTALL_MANPAGES=yes

pre-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/hear ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/msn_protocol_10.html ${PREFIX}/share/doc/${PORTNAME}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
