PORTNAME=	mp-${PAPERSIZE}
PORTVERSION=	3.0.1
CATEGORIES=	print
MASTER_SITES=	LOCAL/obrien
DISTNAME=	mp-3.0.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostScript printing util for ASCII files

CONFLICTS_INSTALL?=	mp-a4

WRKSRC=		${WRKDIR}/mp
LINKS=		digestp filep filofaxp franklinp mailp newsp timemanp timesysp

PAPERSIZE?=	letter
.if ${PAPERSIZE:tl} == a4
INSTALL_TARGET=	install-a4
.endif

MAKEFILE=	Makefile.dist

post-install:
.for a in ${LINKS}
	${LN} -sf mp.1 ${STAGEDIR}${PREFIX}/man/man1/${a}.1
.endfor

.include <bsd.port.mk>
