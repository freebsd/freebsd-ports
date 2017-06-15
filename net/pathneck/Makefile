# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	pathneck
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.cs.cmu.edu/~hnn/pathneck/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Active network path probing tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
MAKEFILE=	Makefile.bsd
MAKE_ARGS=	CC="${CC}"

PLIST_FILES=	sbin/pathneck \
		sbin/get-choke
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS .=,CFLAGS +=,' \
		${WRKSRC}/Makefile.bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathneck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/get-choke ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
