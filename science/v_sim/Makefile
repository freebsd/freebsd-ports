# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	v_sim
PORTVERSION=	3.8.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://gitlab.com/l_sim/${PORTNAME}/-/archive/${PORTVERSION}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Visualization of atomic structures

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
		libyaml.so:textproc/libyaml	\
		libnetcdf.so:science/netcdf	\
		libmsym.so:science/libmsym	\
		libftgl.so:graphics/ftgl	\
		libxc.so:science/libxc
RUN_DEPENDS=	${PYNUMPY}	\
		xcrysden:science/xcrysden	\
		libarchive>0:archivers/libarchive	\
		${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		autoreconf blaslapack compiler:c11 fortran gl gmake gnome	\
		libtool:keepla localbase:ldflags pkgconfig python:3.7+		\
		shebangfix tar:bzip2 xorg
SHEBANG_GLOB=	*.py
USE_XORG=	x11
USE_GNOME=	cairo gtk30 intltool introspection
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_SHELL=${LOCALBASE}/bin/bash
CONFIGURE_ARGS=	--htmldir=${PREFIX}/share/doc --with-openbabel		\
		--with-netcdf=${LOCALBASE} --with-etsf-file-format	\
		--with-xsf --with-cube --with-msym=${LOCALBASE}		\
		--with-msym-inc=-I${LOCALBASE}/include/libmsym		\
		--with-libxc=${LOCALBASE} --enable-python-module
CPPFLAGS+=	${CFLAGS}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS NLS EXAMPLES

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
PLIST_SUB+=	NLS=""
.else
USES+=		gettext-tools
PLIST_SUB+=	NLS="@comment "
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

.include <bsd.port.mk>
