PORTNAME=	basic-engines
PORTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/${TEXLIVE_YEAR}
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${PORTVERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Basic TeX Engines

LIB_DEPENDS=	libpng.so:graphics/png

USES=		libtool localbase pkgconfig tar:xz
USE_TEX=	kpathsea web2c

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		${EXCLUDE_ENGINES:S/^/--disable-/} \
			--disable-missing \
			--with-system-kpathsea \
			--with-system-zlib \
			--with-x=no \
			--without-mf-x-toolkit
.for L in libpng
CONFIGURE_ARGS+=	--with-$L-include=${LOCALBASE}/include \
			--with-$L-libdir=${LOCALBASE}/lib \
			--with-system-$L
.endfor

INSTALL_TARGET=	install-strip

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux libs/xpdf texk/web2c

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

EXCLUDE_ENGINES=	aleph luatex luajittex mf mf-nowin ptex eptex uptex \
			euptex xetex otangle mp pmp upmp web2c web-progs \
			synctex \
			luahbtex \
			luajithbtex \
			mflua \
			mfluajit \
			latex

post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

post-configure:
	cd ${WRKDIR}/${DISTNAME}/libs/xpdf && \
	    ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		LIBS="${LIBS}" \
		${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
		    ${CONFIGURE_ARGS}

.include <bsd.port.mk>
