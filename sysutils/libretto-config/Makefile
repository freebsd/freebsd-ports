# New ports collection makefile for:	libretto-config
# Version required:	1.0
# Date created:		19 Nov 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/12/05 05:35:47 flathill Exp $
#

DISTNAME=	libapm-linux-1.0beta5
PKGNAME=	${PROGRAM_NAME}-1.0b5
CATEGORIES=	sysutils
MASTER_SITES=	http://club.pep.ne.jp/~ishioka/Software/Linux/libapm/

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/libapm
PROGRAM_NAME=	libretto-config
DOCDIR=		${PREFIX}/share/doc/${PROGRAM_NAME}

MAN8=		${PROGRAM_NAME}.8
MANLANG=	. ja

post-install:
# install japanese manpage also :-)
	@${INSTALL_MAN} ${WRKSRC}/libapm-j.man ${PREFIX}/man/ja/man8/${PROGRAM_NAME}.8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README-e.1st ${DOCDIR}/README.1st
	@${INSTALL_DATA} ${WRKSRC}/APM-EXBIOS-e.txt ${DOCDIR}/APM-EXBIOS.txt
	@${MKDIR} ${DOCDIR}/ja
	@${INSTALL_DATA} ${WRKSRC}/README-j.1st ${DOCDIR}/ja/README.1st
	@${INSTALL_DATA} ${WRKSRC}/APM-EXBIOS-j.txt ${DOCDIR}/ja/APM-EXBIOS.txt
.endif

.include <bsd.port.mk>
