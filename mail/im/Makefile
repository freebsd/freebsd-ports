# New ports collection makefile for: IM
# Version required:	76
# Date created:		13 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.2 1998/01/09 21:37:57 max Exp $
#

DISTNAME=	im-76
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/ \
		ftp://ftp.kyushu-u.ac.jp/pub/Misc/mew/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

USE_PERL5=	yes

GNU_CONFIGURE=	yes

MANLANG=	ja
MAN1=		imali.1 imget.1 imsetup.1 imstore.1

PORTDOCDIR=	${PREFIX}/share/doc/im
SAMPLEDIR=	${PREFIX}/share/examples/im
MANFILES=	imali.jis imget.jis imsetup.jis imstore.jis
PORTDOCS=	00readme imget2.jis imput imput.jis

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTDOCDIR}	${SAMPLEDIR}
	@(cd ${WRKSRC}; \
	(cd man;  ${INSTALL_DATA} ${PORTDOCS} ${PORTDOCDIR}); \
	${INSTALL_DATA} dot.im/* ${SAMPLEDIR}; \
	)
.endif
.for f in ${MANFILES}
	@${INSTALL_MAN} ${WRKSRC}/man/${f} \
		${PREFIX}/man/ja/man1/`${BASENAME} ${f} .jis`.1
.endfor

.include <bsd.port.mk>
