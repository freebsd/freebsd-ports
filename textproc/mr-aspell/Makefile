PORTNAME=	${DICT}-aspell
SPELLVERSION=	6-mr-0.10-0
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	textproc

MAINTAINER=	office@FreeBSD.org
COMMENT=	Aspell Marathi dictionary

DICT=	 	mr

# This stops it conflicting on u-deva.cmap|.cset with hi-aspell
post-patch:
	${REINPLACE_CMD} '\,^data_files,s,u-deva\.c[sm][ea][tp],mr-&,g' \
		${WRKSRC}/Makefile.pre
	${REINPLACE_CMD} 's,u-deva,mr-&,' ${WRKSRC}/info ${WRKSRC}/mr.dat \
		${WRKSRC}/u-deva.cset
.for c in cmap cset
	${MV} ${WRKSRC}/u-deva.$c ${WRKSRC}/mr-u-deva.$c
.endfor

.include "${.CURDIR}/../../textproc/aspell/Makefile.inc"
.include <bsd.port.post.mk>
