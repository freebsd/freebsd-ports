# New ports collection makefile for: grace
# Date created:		Dec 28 1998
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	grace
PORTVERSION=	5.1.22
PORTREVISION=	4
CATEGORIES=	math print
#
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/stable/ \
		ftp://ftp.fu-berlin.de/unix/graphics/grace/src/stable/ \
		ftp://ftp.ntua.gr/pub/graphics/grace/src/stable/ \
		ftp://ftp.chg.ru/pub/math/grace/src/stable/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/math/grace/src/stable/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful plotting tool (successor of xmgr)

LIB_DEPENDS=	t1:${PORTSDIR}/devel/t1lib		\
		jpeg.11:${PORTSDIR}/graphics/jpeg	\
		png.6:${PORTSDIR}/graphics/png		\
		tiff.4:${PORTSDIR}/graphics/tiff	\
		fftw.2:${PORTSDIR}/math/fftw		\
		pdf.8:${PORTSDIR}/print/pdflib		\
		netcdf.4:${PORTSDIR}/science/netcdf	\
		Xbae.4:${PORTSDIR}/x11-toolkits/xbae	\
		XmHTML.1:${PORTSDIR}/x11-toolkits/xmhtml

USE_GNOME=	gnometarget
USE_MOTIF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-grace-home=${DATADIR} \
		--with-extra-incpath=${LOCALBASE}/include \
		--with-extra-ldpath=${LOCALBASE}/lib \
		--without-bundled-xbae
ALL_TARGET=	# empty

MAN1=		convcal.1 grace.1 grconvert.1
MLINKS=		grace.1 gracebat.1 \
		grace.1 xmgrace.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xmgrace ${PREFIX}/bin
	@${LN} -sf xmgrace ${PREFIX}/bin/grace
	@${LN} -sf xmgrace ${PREFIX}/bin/gracebat
	${INSTALL_PROGRAM} ${WRKSRC}/auxiliary/convcal ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/grconvert/grconvert ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/auxiliary/fdf2fit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/grace_np/grace_np.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/grace_np/libgrace_np.a ${PREFIX}/lib
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gracerc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gracerc.user ${DATADIR}
	@${MKDIR} ${DATADIR}/auxiliary
	${INSTALL_DATA} ${WRKSRC}/auxiliary/README ${DATADIR}/auxiliary
	${INSTALL_DATA} ${WRKSRC}/auxiliary/convcal.c ${DATADIR}/auxiliary
	${INSTALL_DATA} ${WRKSRC}/auxiliary/magic.grace ${DATADIR}/auxiliary
	@${MKDIR} ${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/fonts/FontDataBase ${DATADIR}/fonts
	@${MKDIR} ${DATADIR}/fonts/enc
	${INSTALL_DATA} ${WRKSRC}/fonts/enc/*.enc ${DATADIR}/fonts/enc
	@${MKDIR} ${DATADIR}/fonts/type1
	${INSTALL_DATA} ${WRKSRC}/fonts/type1/*.afm ${DATADIR}/fonts/type1
	${INSTALL_DATA} ${WRKSRC}/fonts/type1/*.pfb ${DATADIR}/fonts/type1
	@${MKDIR} ${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/*.agr ${DATADIR}/templates
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKSRC}/doc --exclude "*Makefile*" --exclude "*.1" \
		-cf - . | ${TAR} -C ${DOCSDIR} --unlink -xf -
	@${FIND} ${DOCSDIR} -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} \;
	@${FIND} ${DOCSDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${LN} -sf ${DOCSDIR} ${DATADIR}/doc
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/examples --exclude "*Makefile*" \
		-cf - . | ${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${FIND} ${EXAMPLESDIR} -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} \;
	@${FIND} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${LN} -sf ${EXAMPLESDIR} ${DATADIR}/examples
.endif

.include <bsd.port.mk>
