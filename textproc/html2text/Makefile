# New ports collection makefile for:	html2text
# Date created:		7 March 2003
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	html2text
PORTVERSION=	1.3.1
CATEGORIES=	textproc
MASTER_SITES=	http://userpage.fu-berlin.de/~mbayer/tools/ \
		ftp://ftp.ibiblio.org/pub/linux/apps/www/converters/

MAINTAINER=	corecode@corecode.ath.cx
COMMENT=	Converts HTML documents into plain text

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
MANCOMPRESSED=	yes

MAN1=	html2text.1
MAN5=	html2textrc.5

DOCS=	CHANGES COPYING CREDITS KNOWN_BUGS README TODO

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/echo=/s/ -e//' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^DEBUG/s/^/#/; /^CXXFLAGS/s/=/+=/' \
		${WRKSRC}/Makefile.in ${WRKSRC}/libstd/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/html2text ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/html2text.1.gz ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/html2textrc.5.gz ${MANPREFIX}/man/man5
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:C#^#${WRKSRC}/#g} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
