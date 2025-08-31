PORTNAME=	v_sim
DISTVERSION=	3.8.0
PORTREVISION=	14
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Visualization of atomic structures
WWW=		https://gitlab.com/l_sim/v_sim

LICENSE=	CeCILL
LICENSE_NAME=	CeCILL
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	p5-XML-LibXML>0:textproc/p5-XML-LibXML	\
		libarchive>0:archivers/libarchive	\
		xcrysden:science/xcrysden	\
		bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig	\
		libopenbabel.so:science/openbabel	\
		libfreetype.so:print/freetype2	\
		libharfbuzz.so:print/harfbuzz	\
		libyaml.so:textproc/libyaml	\
		libnetcdf.so:science/netcdf	\
		libmsym.so:science/libmsym	\
		libftgl.so:graphics/ftgl	\
		libxc.so:science/libxc
RUN_DEPENDS=	${PYNUMPY}	\
		xcrysden:science/xcrysden	\
		libarchive>0:archivers/libarchive	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		autoreconf blaslapack compiler:c11 fortran gl gmake gnome	\
		libtool:keepla localbase:ldflags pkgconfig python		\
		shebangfix tar:bzip2 xorg
SHEBANG_GLOB=	*.py
USE_XORG=	x11
USE_GNOME=	cairo gtk30 gdkpixbuf intltool introspection pygobject3:run
USE_GL=		gl glu
USE_GITLAB=	yes
GL_ACCOUNT=	l_sim
GL_TAGNAME=	9dc8e5a0b2f4e7237ac50a922b87d234ff56a6e5

GNU_CONFIGURE=	yes
CONFIGURE_SHELL=${LOCALBASE}/bin/bash
CONFIGURE_ARGS=	--htmldir=${PREFIX}/share/doc --with-openbabel		\
		--with-netcdf=${LOCALBASE} --with-etsf-file-format	\
		--with-xsf --with-cube --with-msym=${LOCALBASE}		\
		--with-msym-inc=-I${LOCALBASE}/include/libmsym		\
		--with-libxc=${LOCALBASE} --enable-python-module
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPPFLAGS+=	${CFLAGS}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS NLS EXAMPLES
OPTIONS_SUB=	yes

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug-messages
.endif

.include <bsd.port.options.mk>

.if ${ARCH:Mamd64*} || ${ARCH:Mpowerpc64*}
BUILD_DEPENDS+=	abinit:science/abinit
RUN_DEPENDS+=	abinit:science/abinit
CONFIGURE_ARGS+=--with-abinit
PLIST_SUB+=	AB=""
.else
PLIST_SUB+=	AB="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
USES+=		gettext-tools
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|$${docdir}/examples|${EXAMPLESDIR}|'	\
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's|print sys.prefix|print (sys.prefix)|'	\
		-e 's|print sys.exec_prefix|print (sys.exec_prefix)|'	\
		${WRKSRC}/m4/python.m4

pre-configure-NLS-off:
	${REINPLACE_CMD} -e '/^	po /d' ${WRKSRC}/Makefile.am

pre-configure-DOCS-off:
	${REINPLACE_CMD} -e '/^	Documentation/d' ${WRKSRC}/Makefile.am

pre-configure-EXAMPLES-off:
	${REINPLACE_CMD} -e '/^	examples/d'	\
		${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -e 's|: install-v_simexamplesDATA|:|'	\
		${WRKSRC}/lib/python/Makefile.am

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/lib -type f -name "lib*.so.8.0.0" | \
		${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
