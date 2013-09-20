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

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,^CC .=,CC ?=,' \
			  -e 's,^CFLAGS .=,CFLAGS +=,' \
		${WRKSRC}/Makefile.bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pathneck ${PREFIX}/sbin/pathneck
	${INSTALL_PROGRAM} ${WRKSRC}/get-choke ${PREFIX}/sbin/get-choke
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
