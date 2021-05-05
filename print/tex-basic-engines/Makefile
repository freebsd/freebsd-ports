PORTNAME=	basic-engines
PORTVERSION=	20150521
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20150521-source
DIST_SUBDIR=	TeX

MAINTAINER=	freebsd-tex@FreeBSD.org
COMMENT=	Basic TeX Engines

LIB_DEPENDS=	libpng.so:graphics/png

USES=		pkgconfig libtool tar:xz
USE_TEX=	kpathsea web2c>=20150521_1
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		libs/xpdf \
		texk/web2c
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
EXCLUDE_ENGINES=aleph luatex luajittex mf \
		mf-nowin ptex eptex uptex euptex xetex \
		otangle mp pmp upmp web2c web-progs synctex
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--disable-missing \
		--with-x=no \
		--without-mf-x-toolkit \
		--with-system-zlib \
		--with-system-kpathsea
.for L in libpng
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor
CFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

post-configure:
	cd ${WRKDIR}/${DISTNAME}/libs/xpdf && \
	    ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		LIBS="${LIBS}" \
		${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
		    ${CONFIGURE_ARGS}

.include <bsd.port.mk>
