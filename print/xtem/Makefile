# New ports collection makefile for:   xtem
# Date created:         01 June 1997
# Whom:                 Peter Cornelius <pc@inr.fzk.de>
#
# $FreeBSD$
#

PORTNAME=	xtem
PORTVERSION=	8.00
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.iwd.uni-bremen.de/pub/tex/xtem.v8/
DISTNAME=	${PORTNAME}_texmenu.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82
.if defined(BUILD_IT_ALL)
RUN_DEPENDS+=	gv:${PORTSDIR}/print/gv \
		tex:${PORTSDIR}/print/teTeX
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		hyphen_show.1 xtem.1

pre-everything::
	@${CAT} ${FILESDIR}/makemsg.txt

post-extract:
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/exclude-list ${WRKSRC}

post-patch:
	@${PERL} -pi.bak -e \
		"s|%%TCLSH%%|${PREFIX}/bin/tclsh8.2|g; \
		 s|%%WISH%%|${PREFIX}/bin/wish8.2|g; \
		 s|%%XTEMPATH%%|${PREFIX}/share/xtem|g" ${WRKSRC}/xtem

post-install:
	@${CP} ${FILESDIR}/xtem_locals_german/[a-z]* \
		${PREFIX}/share/xtem_locals_german

.include <bsd.port.mk>
