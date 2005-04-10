# New ports collection makefile for: ppxp
# Date created:		24 Dec 1999
# Whom:			Norio Suzuki <nosuzuki@e-mail.ne.jp>
#			KUNISHIMA Takeo <kunishi@c.oka-pu.ac.jp>
#			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $FreeBSD$
#

PORTNAME=	ppxp
PORTVERSION=	2001080415
PORTREVISION=	2
.if defined(WITH_TCLJP)
CATEGORIES+=	net tk80
.else
CATEGORIES+=	net tk83
.endif
MASTER_SITES=	http://www.dsl.gr.jp/~manabe/PPxP/packages/	\
		http://www.linet.gr.jp/~manabe/PPxP/packages/

MAINTAINER=	nosuzuki@postcard.st
COMMENT=	A new and easy to use PPP software

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms
.if defined(WITH_TCLJP)
BUILD_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80 \
		tclsh8.0jp:${PORTSDIR}/japanese/tcl80
LIB_DEPENDS+=	tcl80jp.1:${PORTSDIR}/japanese/tcl80
RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80 \
		tclsh8.0jp:${PORTSDIR}/japanese/tcl80
.else
BUILD_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83 \
		tclsh8.3:${PORTSDIR}/lang/tcl83
LIB_DEPENDS+=	tcl83.1:${PORTSDIR}/lang/tcl83
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83 \
		tclsh8.3:${PORTSDIR}/lang/tcl83
.endif

USE_PERL5_BUILD=yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
.if defined(WITH_TCLJP)
CONFIGURE_ARGS+= --with-tclsh=${PREFIX}/bin/tclsh8.0jp \
		--with-wish=${PREFIX}/bin/wish8.0jp \
		--with-tcl-includes=${PREFIX}/include/tcl8.0jp \
		--with-tcl-config=${PREFIX}/lib/tcl8.0jp/tclConfig.sh \
		--with-tk-config=${PREFIX}/lib/tk8.0jp/tkConfig.sh
.else
CONFIGURE_ARGS+= --with-tclsh=${PREFIX}/bin/tclsh8.3 \
		--with-wish=${PREFIX}/bin/wish8.3 \
		--with-tcl-includes=${PREFIX}/include/tcl8.3 \
		--with-tcl-config=${PREFIX}/lib/tcl8.3/tclConfig.sh \
		--with-tk-config=${PREFIX}/lib/tk8.3/tkConfig.sh
.endif
MAN1=		PPxP.1 plast.1
MAN5=		ppxp-files.5
MANLANG=	ja

WRKSRC=		${WRKDIR}/ppxp
MAKEFILE=	makefile

DOC_C=		QuickStart.txt
DOC_ja_JP=	QuickStart.txt QuickUsage.txt guide-1.html guide-2.html \
		guide-3.html guide-4.html guide-5.html guide-6.html \
		guide-7.html guide-8.html guide-9.html guide-10.html \
		guide-11.html guide.html Answers.txt Report.txt

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.else
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.if ${ARCH} == "ia64"
BROKEN=		"Coredump during build on ia64"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f '{}' ';'
	@${PERL} -pi -e 's/^CFLAGS/#$$&/' ${WRKSRC}/configure

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
	csh ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
