# New ports collection makefile for:	antiword
# Date created:				8 June 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	antiword
PORTVERSION=	0.34
CATEGORIES=	textproc
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	"An application to display Microsoft(tm) Word files"

USE_REINPLACE=	yes
INSTALL_TARGET=	global_install

MAN1=		antiword.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
		-e 's,/usr/share,${PREFIX}/share,g' \
		${WRKSRC}/Makefile.* ${WRKSRC}/*.[ch]

post-install:
	@${INSTALL_MAN} ${WRKSRC}/Docs/antiword.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
