# New ports collection makefile for: IM
# Version required:	100
# Date created:		13 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	im-100
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/ \
		ftp://ftp.kyushu-u.ac.jp/pub/Misc/mew/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --libdir=${PREFIX}/etc
# If you use RPOP instead of APOP, comment out following line.
#CONFIGURE_ARGS+=--enable-rpop

PORTDOCDIR=	${PREFIX}/share/doc/im
SAMPLEDIR=	${PREFIX}/share/examples/im
PORTDOCS=	00changes 00copyright 00copyright.jis 00perl 00readme 00usage

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTDOCDIR}/man ${SAMPLEDIR}
	@cd ${WRKSRC}; \
	${INSTALL_DATA} ${PORTDOCS} ${PORTDOCDIR}; \
	${INSTALL_DATA} man/* ${PORTDOCDIR}/man; \
	${INSTALL_DATA} dot.im/* ${SAMPLEDIR}
.endif

.include <bsd.port.mk>
