# New ports collection makefile for:   xtem
# Version required:     7.00
# Date created:         01 June 1997
# Whom:                 Peter Cornelius <pc@inr.fzk.de>
#
# $FreeBSD$

DISTNAME=	xtem_texmenu.7.00
PKGNAME=	xtem-7.00
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.iwd.uni-bremen.de/pub/tex/xtem.v7/

MAINTAINER=     ports@FreeBSD.org

RUN_DEPENDS=	wishx:${PORTSDIR}/lang/tclX80
.if defined(BUILD_IT_ALL)
RUN_DEPENDS+=	gv:${PORTSDIR}/print/gv \
		tex:${PORTSDIR}/print/teTeX
.endif

WRKSRC=		${WRKDIR}/${PKGNAME}
MAN1=		hyphen_show.1 xtem.1

pre-extract:
	@${CAT} ${FILESDIR}/makemsg.txt

post-extract:
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/exclude-list ${WRKSRC}

post-patch:
	@/usr/bin/perl -pi.bak -e "s|\@WISHX\@|${PREFIX}/bin/wishx|; \
		s|\@TCLSH\@|${PREFIX}/bin/tclsh8.0|; \
		s|\@XTEMPATH\@|${PREFIX}/share/xtem|" \
		${WRKSRC}/xtem

post-install:
	@${CP} ${FILESDIR}/xtem_locals_german/[a-z]* \
		${PREFIX}/share/xtem_locals_german
# clean up left-overs...
	@${RM} -f ${PREFIX}/share/xtem_locals_*/.nfs*

.include <bsd.port.mk>
