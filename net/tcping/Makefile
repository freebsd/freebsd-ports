# Created by: Dryice Liu
# $FreeBSD$

PORTNAME=	tcping
PORTVERSION=	1.3.5
CATEGORIES=	net
MASTER_SITES=	http://www.linuxco.de/tcping/ \
		http://dryice.name/computer/FreeBSD/distfiles/

MAINTAINER=	dryice@dryice.name
COMMENT=	Do a TCP connect to the given IP/port combination

DOCS=		README

NO_STAGE=	yes
do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -DHAVE_HSTRERROR -o tcping tcping.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcping ${PREFIX}/bin/tcping
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
