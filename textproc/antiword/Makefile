# New ports collection makefile for:	antiword
# Date created:				8 June 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	antiword
PORTVERSION=	0.37
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	An application to display Microsoft(tm) Word files

USE_GMAKE=	yes

INSTALL_TARGET=	global_install

MAN1=		antiword.1
PORTDOCS=	COPYING ChangeLog Emacs Exmh FAQ History Mozilla Mutt Netscape \
		QandA ReadMe antiword.1 antiword.man antiword.php testdoc.doc

CFLAGS+=	-DNDEBUG
MAKE_ENV+=	CC="${CC}"

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's,/usr/local,${PREFIX},g' \
		-e 's,/usr/share,${PREFIX}/share,g'
	@${REINPLACE_CMD} -E 's|LD|CC|g; /^(CC|CFLAGS)/d' ${WRKSRC}/${MAKEFILE}

post-install:
	@${INSTALL_MAN} ${WRKSRC}/Docs/antiword.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/Docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
