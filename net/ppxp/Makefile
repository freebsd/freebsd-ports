# New ports collection makefile for: ppxp
# Version required:	0.98112523
# Date created:		16 June 1998
# Whom:			Norio Suzuki
# Based on:		KUNISHIMA Takeo <kunishi@c.oka-pu.ac.jp>
#
# $Id$
#

# The option "TCLJP" doesn't work fine on 3.0-CURRENT.

DISTNAME=	ppxp-0.98112523
CATEGORIES=	net tk80
.if defined(TCLJP)
CATEGORIES+=	japanese
.endif
MASTER_SITES=	http://www.dsl.ics.tut.ac.jp/~manabe/PPxP/packages/	\
		http://www.dsl.gr.jp/~manabe/PPxP/packages/

MAINTAINER=	nosuzuki@e-mail.ne.jp

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms
.if defined(TCLJP)
BUILD_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80 \
		tclsh8.0jp:${PORTSDIR}/japanese/tcl80
RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80 \
		tclsh8.0jp:${PORTSDIR}/japanese/tcl80
.else
BUILD_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80 \
		tclsh8.0:${PORTSDIR}/lang/tcl80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80 \
		tclsh8.0:${PORTSDIR}/lang/tcl80
.endif

WRKSRC=		${WRKDIR}/ppxp
USE_GMAKE=	yes
MAKEFILE=	makefile
GNU_CONFIGURE=	yes
.if defined(TCLJP)
CONFIGURE_ARGS+= --with-tclsh=${PREFIX}/bin/tclsh8.0jp \
		--with-wish=${PREFIX}/bin/wish8.0jp \
		--with-tcl-includes=${PREFIX}/include/tcl8.0jp \
		--with-tcl-config=${PREFIX}/lib/tcl8.0jp/tclConfig.sh \
		--with-tk-config=${PREFIX}/lib/tk8.0jp/tkConfig.sh
.else
CONFIGURE_ARGS+= --with-tclsh=${PREFIX}/bin/tclsh8.0 \
		--with-wish=${PREFIX}/bin/wish8.0 \
		--with-tcl-includes=${PREFIX}/include/tcl8.0 \
		--with-tcl-config=${PREFIX}/lib/tcl8.0/tclConfig.sh \
		--with-tk-config=${PREFIX}/lib/tk8.0/tkConfig.sh
.endif
MAN1=		PPxP.1
MAN5=		ppxp-files.5
MANLANG=	ja

DOC_C=		QuickStart.txt
DOC_ja_JP=	QuickStart.txt guide-1.html guide-2.html \
		guide-3.html guide-4.html guide-5.html guide-6.html \
		guide-7.html guide-8.html guide-9.html guide-10.html \
		guide.html

post-patch:
	@find ${WRKSRC} -name '*.orig' -exec ${RM} -f '{}' ';'

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/ja_JP/PPxP.1 ${PREFIX}/man/${MANLANG}/man1
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
	@${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/ppxp/tcl

.include <bsd.port.mk>
