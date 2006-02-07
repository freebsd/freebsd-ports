# New ports collection makefile for:	pathneck
# Date Created:				22 Dec 2005
# Whom:					Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	pathneck
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://gs274.sp.cs.cmu.edu/www/pathneck/ \
		http://www.unixified.net/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	babak@farrokhi.net
COMMENT=	Active network path probing tool

PLIST_FILES=	sbin/pathneck \
		sbin/get-choke
PORTDOCS=	COPYING ChangeLog README
MAKEFILE=	Makefile.bsd

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
