# New ports collection makefile for:	Panda
# Date created:		28 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	panda
PORTVERSION=	0.4.p1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	panda
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g:S/p/rc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.p/-rc/}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${PREFIX}/lib" \
		LIBS="${PTHREAD_LIBS}"
MAKE_ARGS=	NOPROFILE=true
INSTALLS_SHLIB=	yes

MAN3=		checkinfo.3 initpanda.3 makedate.3 nowdate.3 \
		panda-textmodes.3 panda-xobjectmodes.3 pdfclose.3 \
		pdfopen.3 pdfpage.3 setauthor.3 setcharacterspacing.3 \
		setcreator.3 setfont.3 setfontmode.3 setfontsize.3 \
		sethorizontalscaling.3 setkeywords.3 setleading.3 \
		setsubject.3 settitle.3 setwordspacing.3

DOCS=		AUTHORS BUGS CONTRIBUTORS ChangeLog \
		DEV-HINTS README TODO UNDERWAY
EXAMPLES=	IMAGES *.jpg *.png *.tif main.c legacymain.c

post-configure:
# GNU make doesn't have a -V option, so we have to add a shot_VARIABLE
# target for each variable and run gmake show_VARIABLE to look it up.
	cd ${WRKSRC} && ${PERL} -pe 's/%%(\w+)%%/ \
		open(H, ">> Makefile"); \
		print H "show_$$1:; \@echo \$$($$1)\n"; \
		close(H); \
		$$_ = `${GMAKE} show_$$1`; \
		chomp; \
		$$_; \
		/eg' \
		${FILESDIR}/BSDMakefile > ${WRKSRC}/BSDMakefile

pre-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f BSDMakefile ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f BSDMakefile ${MAKE_ARGS} ${INSTALL_TARGET}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}/
.endfor
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
