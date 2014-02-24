# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	pathneck
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.cs.cmu.edu/~hnn/pathneck/ \
		http://gs274.sp.cs.cmu.edu/www/pathneck/ \
		http://www.unixified.net/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Active network path probing tool

PLIST_FILES=	sbin/pathneck \
		sbin/get-choke
PORTDOCS=	COPYING ChangeLog README
MAKEFILE=	Makefile.bsd

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,^CC .=,CC ?=,' \
			  -e 's,^CFLAGS .=,CFLAGS +=,' \
		${WRKSRC}/Makefile.bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathneck ${STAGEDIR}${PREFIX}/sbin/pathneck
	${INSTALL_PROGRAM} ${WRKSRC}/get-choke \
		${STAGEDIR}${PREFIX}/sbin/get-choke
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
