# New ports collection makefile for: IM
# Date created:		13 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	im
PORTVERSION=	147
CATEGORIES=	mail
MASTER_SITES=	http://tats.haun.org/im/ \
		${MASTER_SITE_PORTS_JP}

MAINTAINER=	kiri@FreeBSD.org
COMMENT=	Set of user interfaces of Email and NetNews

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --libdir=${PREFIX}/etc
# If you use RPOP instead of APOP, comment out following line.
#CONFIGURE_ARGS+=--enable-rpop
MAKE_ARGS=	prefix=${PREFIX} imlibdir=${PREFIX}/etc/im

PORTDOCDIR=	${PREFIX}/share/doc/im
SAMPLEDIR=	${PREFIX}/share/examples/im
MYPORTDOCS=	00changes 00copyright 00copyright.jis 00perl 00readme 00usage

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTDOCDIR}/man ${SAMPLEDIR}
	@cd ${WRKSRC}; \
	${INSTALL_DATA} ${MYPORTDOCS} ${PORTDOCDIR}; \
	${INSTALL_DATA} man/* ${PORTDOCDIR}/man; \
	${INSTALL_DATA} dot.im/* ${SAMPLEDIR}
.endif

## for make PLIST (only maintainer use)
#arrange:
#	${MAKE} -DPLIST_OVERRIDE \
#	DIRRMDEPTH=1 plist

.include <bsd.port.mk>
