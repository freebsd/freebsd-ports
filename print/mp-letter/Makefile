# ex:ts=8
# Ports collection makefile for:  mp (letter)
# Date created:			  11 July 1996
# Whom:				  David O'Brien <obrien@cs.ucdavis.edu>
#
# $FreeBSD$
#

PORTNAME=	mp-${PAPERSIZE}
PORTVERSION=	3.0.1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.NUXI.com/pub/misc/ \
		ftp://ftp.win.tue.nl/pub/mail/
DISTNAME=	mp-3.0.1

MAINTAINER=	obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/mp
MAN1=		mp.1
MLINKS=		mp.1 digestp.1	- filep.1	- filofaxp.1 \
		- franklinp.1	- mailp.1	- newsp.1 \
		- timemanp.1	- timesysp.1

PAPERSIZE?=	letter
.if ${PAPERSIZE} == a4
INSTALL_TARGET= install-a4
.endif

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

.include <bsd.port.mk>
