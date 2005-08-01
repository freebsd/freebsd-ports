# New ports collection makefile for:	multitail
# Date created:				10 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	multitail
PORTVERSION=	3.6.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Tail multiple files on console with ncurses

USE_REINPLACE=	yes
USE_GMAKE=	yes

MAN1=		multitail.1

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d ; s/^CFLAGS=/CFLAGS+=/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/etc/multitail.conf,${PREFIX}/etc/multitail.conf,' \
		${WRKSRC}/mt.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/multitail.conf ${PREFIX}/etc/multitail.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
