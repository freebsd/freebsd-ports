# New ports collection makefile for:	libretto-config
# Date created:		19 Nov 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libretto-config
PORTVERSION=	1.0.b5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://club.pep.ne.jp/~ishioka/Software/Linux/libapm/
DISTNAME=	libapm-linux-1.0beta5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libretto BIOS Setting Program

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/libapm
DOCDIR=		${PREFIX}/share/doc/${PORTNAME}

MAN8=		${PORTNAME}.8
MANLANG=	. ja

post-install:
# install japanese manpage also :-)
	@${INSTALL_MAN} ${WRKSRC}/libapm-j.man ${PREFIX}/man/ja/man8/${PORTNAME}.8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README-e.1st ${DOCDIR}/README.1st
	@${INSTALL_DATA} ${WRKSRC}/APM-EXBIOS-e.txt ${DOCDIR}/APM-EXBIOS.txt
	@${MKDIR} ${DOCDIR}/ja
	@${INSTALL_DATA} ${WRKSRC}/README-j.1st ${DOCDIR}/ja/README.1st
	@${INSTALL_DATA} ${WRKSRC}/APM-EXBIOS-j.txt ${DOCDIR}/ja/APM-EXBIOS.txt
.endif

.include <bsd.port.mk>
