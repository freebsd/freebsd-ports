# New ports collection makefile for: ppxp
# Date created:		24 Dec 1999
# Whom:			Norio Suzuki <nosuzuki@e-mail.ne.jp>
#			KUNISHIMA Takeo <kunishi@c.oka-pu.ac.jp>
#			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $FreeBSD$
#

PORTNAME=	ppxp
PORTVERSION=	0.99120923
CATEGORIES+=	net tk82
MASTER_SITES=	http://www.dsl.gr.jp/~manabe/PPxP/packages/	\
		http://www.linet.gr.jp/~manabe/PPxP/packages/	\
		http://www.dsl.ics.tut.ac.jp/~manabe/PPxP/packages/

MAINTAINER=	nosuzuki@e-mail.ne.jp

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms
.if defined(WITH_TCLJP)
BUILD_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80 \
		tclsh8.0jp:${PORTSDIR}/japanese/tcl80
LIB_DEPENDS+=	tcl80jp.1:${PORTSDIR}/japanese/tcl80
RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80 \
		tclsh8.0jp:${PORTSDIR}/japanese/tcl80
.else
BUILD_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82 \
		tclsh8.2:${PORTSDIR}/lang/tcl82
LIB_DEPENDS+=	tcl82.1:${PORTSDIR}/lang/tcl82
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82 \
		tclsh8.2:${PORTSDIR}/lang/tcl82
.endif

WRKSRC=		${WRKDIR}/ppxp
USE_GMAKE=	yes
MAKEFILE=	makefile
GNU_CONFIGURE=	yes
.if defined(WITH_TCLJP)
CONFIGURE_ARGS+= --with-tclsh=${PREFIX}/bin/tclsh8.0jp \
		--with-wish=${PREFIX}/bin/wish8.0jp \
		--with-tcl-includes=${PREFIX}/include/tcl8.0jp \
		--with-tcl-config=${PREFIX}/lib/tcl8.0jp/tclConfig.sh \
		--with-tk-config=${PREFIX}/lib/tk8.0jp/tkConfig.sh
.else
CONFIGURE_ARGS+= --with-tclsh=${PREFIX}/bin/tclsh8.2 \
		--with-wish=${PREFIX}/bin/wish8.2 \
		--with-tcl-includes=${PREFIX}/include/tcl8.2 \
		--with-tcl-config=${PREFIX}/lib/tcl8.2/tclConfig.sh \
		--with-tk-config=${PREFIX}/lib/tk8.2/tkConfig.sh
.endif
MAN1=		PPxP.1 plast.1
MAN5=		ppxp-files.5
MANLANG=	ja

DOC_C=		QuickStart.txt
DOC_ja_JP=	QuickStart.txt QuickUsage.txt guide-1.html guide-2.html \
		guide-3.html guide-4.html guide-5.html guide-6.html \
		guide-7.html guide-8.html guide-9.html guide-10.html \
		guide-11.html guide.html Answers.txt Report.txt

post-patch:
	@find ${WRKSRC} -name '*.orig' -exec ${RM} -f '{}' ';'

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/ja_JP/PPxP.1 ${PREFIX}/man/${MANLANG}/man1
	@${INSTALL_MAN} ${WRKSRC}/doc/ja_JP/plast.1 ${PREFIX}/man/${MANLANG}/man1
	@${INSTALL_MAN} ${WRKSRC}/doc/ja_JP/ppxp-files.5 ${PREFIX}/man/${MANLANG}/man5
	@${MKDIR} ${PREFIX}/share/doc/ppxp/C
.for file in ${DOC_C}
	@${INSTALL_DATA} ${WRKSRC}/doc/C/${file} ${PREFIX}/share/doc/ppxp/C
.endfor
	@${MKDIR} ${PREFIX}/share/doc/ppxp/ja
.for file in ${DOC_ja_JP}
	@${INSTALL_DATA} ${WRKSRC}/doc/ja_JP/${file} ${PREFIX}/share/doc/ppxp/ja
.endfor
	@${MKDIR} ${PREFIX}/share/doc/tkppxp
	@${INSTALL_DATA} ${WRKSRC}/console/tcltk/README ${PREFIX}/share/doc/tkppxp
	@${MKDIR} ${PREFIX}/share/doc/xppxp
	@${INSTALL_DATA} ${WRKSRC}/console/xppxp/README ${PREFIX}/share/doc/xppxp
	csh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
