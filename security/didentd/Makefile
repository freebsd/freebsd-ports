# Created by: Doobee R. Tzeck
# $FreeBSD$

PORTNAME=	didentd
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	http://c0re.23.nu/c0de/didentd/ \
		http://untergrund.bewaff.net/~drt/c0re.jp/c0de/didentd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular RFC1423 (identd) server sending encrypted audit tokens

RUN_DEPENDS=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

ALL_TARGET=	all
INSTALL_TARGET=	install

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} 's,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/didentd
	${INSTALL_MAN} ${WRKSRC}/BLURB ${PREFIX}/share/doc/didentd
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/didentd
	${INSTALL_MAN} ${WRKSRC}/INTERNALS ${PREFIX}/share/doc/didentd
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/didentd
	${INSTALL_MAN} ${WRKSRC}/THANKS ${PREFIX}/share/doc/didentd
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/didentd
	${INSTALL_MAN} ${WRKSRC}/WHY-ENCRYPT ${PREFIX}/share/doc/didentd
	${INSTALL_MAN} ${WRKSRC}/WHY-TAP ${PREFIX}/share/doc/didentd
.endif

.include <bsd.port.mk>
