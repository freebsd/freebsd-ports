# New ports collection makefile for:	DCL
# Date created:		30 January 2005
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dcl
PORTVERSION=	5.3.1
CATEGORIES=	science graphics
MASTER_SITES=	http://www.gfd-dennou.org/arch/dcl/

MAINTAINER=	murakami@ahs.scitec.kobe-u.ac.jp
COMMENT=	Scientific graphic library for geoscience

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --libdir=${PREFIX}/lib/${PORTNAME}-${PORTVERSION}  --disable-gtk2 --disable-gtk --with-x

DOCFILES=	CHECK CREDITS HISTORY README README_clrmap README_gt2dlib \
		README_itr51 README_pslib README_umfmap
DEMODIRS=	gokuraku grph1 grph2 math1 math2 misc1 misc2 rakuraku
DEMOGOKUDIR=	hop jump layout step u1d u2d
DEMOGRPH1DIR=	scpack sgpack slpack
DEMOGRPH2DIR=	grpack ucpack udegpk ulpack umpack uspack uupack uxyzpk ximage
DEMOMATH1DIR=	blklib chrlib fnclib gnmlib ifalib indxlib intlib lrllib \
		oslib rfalib rfblib sublib syslib vialib viblib vralib vrblib
DEMOMATH2DIR=	fftlib intrlib rnmlib vstlib
DEMOMISC1DIR=	bitlib chglib chklib chnlib clcklib datelib fmtlib hexlib \
		misclib randlib timelib
DEMORAKUDIR=	color kihon layout map3d miss quick u2d uspack uxyz

RESTRICTED=	"No commercial use"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/Makefile ${EXAMPLESDIR}
.for i in ${DEMODIRS}
	${MKDIR} ${EXAMPLESDIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/demo/${i}/Makefile ${EXAMPLESDIR}/${i}
.endfor
.for i in ${DEMOGOKUDIR}
	${MKDIR} ${EXAMPLESDIR}/gokuraku/${i}
	${INSTALL_DATA} ${WRKSRC}/demo/gokuraku/${i}/* ${EXAMPLESDIR}/gokuraku/${i}/
.endfor
.for i in ${DEMOGRPH1DIR}
	${MKDIR} ${EXAMPLESDIR}/grph1/${i}
	${INSTALL_DATA} ${WRKSRC}/demo/grph1/${i}/* ${EXAMPLESDIR}/grph1/${i}/
.endfor
.for i in ${DEMOGRPH2DIR}
	${MKDIR} ${EXAMPLESDIR}/grph2/${i}
	${INSTALL_DATA} ${WRKSRC}/demo/grph2/${i}/* ${EXAMPLESDIR}/grph2/${i}/
.endfor
.for i in ${DEMOMATH1DIR}
	${MKDIR} ${EXAMPLESDIR}/math1/${i}
	${INSTALL_DATA} ${WRKSRC}/demo/math1/${i}/* ${EXAMPLESDIR}/math1/${i}/
.endfor
.for i in ${DEMOMATH2DIR}
	${MKDIR} ${EXAMPLESDIR}/math2/${i}
	${INSTALL_DATA} ${WRKSRC}/demo/math2/${i}/* ${EXAMPLESDIR}/math2/${i}/
.endfor
.for i in ${DEMOMISC1DIR}
	${MKDIR} ${EXAMPLESDIR}/misc1/${i}
	${INSTALL_DATA} ${WRKSRC}/demo/misc1/${i}/* ${EXAMPLESDIR}/misc1/${i}/
.endfor
.for i in ${DEMORAKUDIR}
	${MKDIR} ${EXAMPLESDIR}/rakuraku/${i}
	${INSTALL_DATA} ${WRKSRC}/demo/rakuraku/${i}/* ${EXAMPLESDIR}/rakuraku/${i}/
.endfor
.endif
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.include <bsd.port.mk>
