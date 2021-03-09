# Created by: Stephen Montgomery-Smith <stephen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sage
PORTVERSION=	9.2
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	https://mirrors.xmission.com/sage/src/		\
		http://mirrors.xmission.com/sage/src/		\
		https://www-ftp.lip6.fr/pub/math/sagemath/src/	\
		https://mirrors.mit.edu/sage/src/		\
		https://files.sagemath.org/src/			\
		ftp://www-ftp.lip6.fr/pub/math/sagemath/src/
#MASTER_SITES=	ftp://www-ftp.lip6.fr/pub/math/sagemath/devel/
PKGNAMESUFFIX=	-math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Open source Mathematics software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	bash:shells/bash		\
		dash:shells/dash		\
		cmake:devel/cmake		\
		dreadnaut:math/nauty		\
		${PYTHON_PKGNAMEPREFIX}alabaster>0:textproc/py-alabaster@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}backcall>0:devel/py-backcall@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}bleach>0:www/py-bleach@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}brial>0:math/py-brial@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cvxopt>0:math/py-cvxopt@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cycler>0:devel/py-cycler@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cypari2>0:math/py-cypari2@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}entrypoints>0:devel/py-entrypoints@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}fpylll>0:math/py-fpylll@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}gmpy2-devel>0:math/py-gmpy2-devel@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}imagesize>0:graphics/py-imagesize@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ipykernel5>0:devel/py-ipykernel5@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>0:devel/py-ipython_genutils@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}itsdangerous>0:security/py-itsdangerous@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}Jinja2>0i:devel/py-Jinja2@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jupyter_core>0:devel/py-jupyter_core@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jupyter_client>0:devel/py-jupyter_client@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}kiwisolver>0:math/py-kiwisolver@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}mistune>0:textproc/py-mistune@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}nbconvert>0:devel/py-nbconvert@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}notebook>0:www/py-notebook@${PY_FLAVOR}\
		${PYNUMPY}			\
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pandocfilters>0:textproc/py-pandocfilters@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}parso>0:textproc/py-parso@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}path.py>0:devel/py-path.py@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pickleshare>0:databases/py-pickleshare@${PY_FLAVOR}\
		${PY_PILLOW}			\
		${PYTHON_PKGNAMEPREFIX}pkgconfig>0:devel/py-pkgconfig@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pplpy>0:math/py-pplpy@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}prometheus-client>0:net-mgmt/py-prometheus-client@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>0:devel/py-prompt-toolkit@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ptyprocess>0:sysutils/py-ptyprocess@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pycparser>0:devel/py-pycparser@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pyrsistent>0:devel/py-pyrsistent@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}rpy2>0:math/py-rpy2@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}scandir>0:sysutils/py-scandir@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}send2trash>0:deskutils/py-send2trash@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}simplegeneric>0:devel/py-simplegeneric@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}snowballstemmer>0:textproc/py-snowballstemmer@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-applehelp>0:textproc/py-sphinxcontrib-applehelp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-devhelp>0:textproc/py-sphinxcontrib-devhelp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-htmlhelp>0:textproc/py-sphinxcontrib-htmlhelp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-jsmath>0:textproc/py-sphinxcontrib-jsmath@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-qthelp>0:textproc/py-sphinxcontrib-qthelp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-serializinghtml>0:textproc/py-sphinxcontrib-serializinghtml@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-websupport>0:textproc/py-sphinxcontrib-websupport@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}terminado>0:net/py-terminado@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}testpath>0:devel/py-testpath@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}traitlets>0:devel/py-traitlets@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}traitlets>0:devel/py-traitlets@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}vcversioner>0:devel/py-vcversioner@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}wcwidth>0:devel/py-wcwidth@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}webencodings>0:converters/py-webencodings@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}widgetsnbextension>0:devel/py-widgetsnbextension@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}zipp>0:devel/py-zipp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR}\
		fflas-ffpack-config:math/fflas-ffpack	\
		fricas>0:math/fricas		\
		gfan:math/gfan			\
		git:devel/git			\
		gp2c:math/gp2c			\
		jmol:science/jmol		\
		libatomic_ops>0:devel/libatomic_ops	\
		MathJax>0:www/mathjax		\
		maxima>0:math/maxima		\
		p5-XML-Writer>0:textproc/p5-XML-Writer	\
		p5-XML-LibXML>0:textproc/p5-XML-LibXML	\
		p5-XML-LibXSLT>0:textproc/p5-XML-LibXSLT\
		p5-File-Slurp>0:devel/p5-File-Slurp	\
		p5-JSON>0:converters/p5-JSON	\
		p5-SVG>0:textproc/p5-SVG	\
		p5-MongoDB>0:databases/p5-MongoDB	\
		p5-Term-ReadLine-Gnu>0:devel/p5-Term-ReadLine-Gnu\
		palp>0:math/palp		\
		pandoc:textproc/hs-pandoc	\
		pari-elldata>0:math/pari_elldata\
		pari-galdata>0:math/pari_galdata\
		pari-galpol>0:math/pari_galpol	\
		pari-nftables>0:math/pari_nftables	\
		pari-seadata>0:math/pari_seadata\
		QuadraticSieve:math/flintqs	\
		ninja:devel/ninja		\
		gpatch:devel/patch		\
		rubiks>0:math/rubiks		\
		sympow:math/sympow		\
		tachyon:graphics/tachyon	\
		three.js>0:www/threejs		\
		yasm:devel/yasm			\
		gtar:archivers/gtar		\
		convert:graphics/ImageMagick6	\
		ffmpeg:multimedia/ffmpeg	\
		${LOCALBASE}/lib/libBLT.a:x11-toolkits/blt
LIB_DEPENDS=	libarb.so:math/arb		\
		libboost_thread.so:devel/boost-libs	\
		libbraiding.so:math/libbraiding	\
		libbrial.so:math/brial		\
		libCbc.so:math/cbc		\
		libcdd.so:math/cddlib		\
		libcliquer.so:math/cliquer	\
		libcurl.so:ftp/curl		\
		libeantic.so:math/e-antic	\
		libec.so:math/eclib		\
		libecl.so:lang/ecl		\
		libecm.so:math/gmp-ecm		\
		libflint.so:math/flint2		\
		libfplll.so:math/fplll		\
		libfreetype.so:print/freetype2	\
		libgc.so:devel/boehm-gc		\
		libgc-threaded.so:devel/boehm-gc-threaded\
		libgf2x.so:math/gf2x		\
		libgivaro.so:math/givaro	\
		libglpk.so:math/glpk		\
		libgap.so:math/gap		\
		libgmp.so:math/gmp		\
		libgsl.so:math/gsl		\
		libhomfly.so:math/libhomfly	\
		libiml.so:math/iml		\
		libisl.so:devel/isl		\
		libLfunction.so:math/lcalc	\
		libffi.so:devel/libffi		\
		libgd.so:graphics/gd		\
		libgiac.so:math/giacxcas	\
		liblinbox.so:math/linbox	\
		liblrcalc.so:math/lrcalc	\
		liblrs.so:math/lrslib	\
		libm4ri.so:math/m4ri		\
		libm4rie.so:math/m4rie		\
		libmpc.so:math/mpc		\
		libmpfi.so:math/mpfi		\
		libmpfr.so:math/mpfr		\
		libmpir.so:math/mpir		\
		libntl.so:math/ntl		\
		libpari.so:math/pari		\
		libpcre.so:devel/pcre		\
		libplanarity.so:math/planarity	\
		libpng.so:graphics/png		\
		libppl.so:devel/ppl		\
		libpynac.so:math/pynac		\
		libR.so:math/R			\
		librw.so:math/rankwidth		\
		libSingular.so:math/singular	\
		libamd.so:math/suitesparse	\
		libsemigroups.so:math/libsemigroups	\
		libsymmetrica.so:math/symmetrica\
		libzmq.so:net/libzmq4		\
		libzn_poly-0.9.so:math/zn_poly	\
		libqd.so:math/qd		\
		libisl.so:devel/isl		\
		libblas.so:math/blas		\
		libicuuc.so:devel/icu		\
		libtiff.so:graphics/tiff	\
		liblapack.so:math/lapack	\
		libedit.so:devel/libedit	\
		libwebp.so:graphics/webp	\
		libpcre2-8.so:devel/pcre2	\
		libgdbm.so:databases/gdbm	\
		liblcms2.so:graphics/lcms2	\
		libopenjp2.so:graphics/openjpeg
RUN_DEPENDS=	bash:shells/bash		\
		dreadnaut:math/nauty		\
		${PYTHON_PKGNAMEPREFIX}alabaster>0:textproc/py-alabaster@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}backcall>0:devel/py-backcall@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}bleach>0:www/py-bleach@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}brial>0:math/py-brial@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cvxopt>0:math/py-cvxopt@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cycler>0:devel/py-cycler@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cypari2>0:math/py-cypari2@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}entrypoints>0:devel/py-entrypoints@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}fpylll>0:math/py-fpylll@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}gmpy2-devel>0:math/py-gmpy2-devel@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}imagesize>0:graphics/py-imagesize@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ipykernel5>0:devel/py-ipykernel5@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>0:devel/py-ipython_genutils@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}itsdangerous>0:security/py-itsdangerous@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jupyter_core>0:devel/py-jupyter_core@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}jupyter_client>0:devel/py-jupyter_client@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}kiwisolver>0:math/py-kiwisolver@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}mistune>0:textproc/py-mistune@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}nbconvert>0:devel/py-nbconvert@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}notebook>0:www/py-notebook@${PY_FLAVOR}\
		${PYNUMPY}			\
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pandocfilters>0:textproc/py-pandocfilters@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}parso>0:textproc/py-parso@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}path.py>0:devel/py-path.py@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pickleshare>0:databases/py-pickleshare@${PY_FLAVOR}\
		${PY_PILLOW}			\
		${PYTHON_PKGNAMEPREFIX}pkgconfig>0:devel/py-pkgconfig@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pplpy>0:math/py-pplpy@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}prometheus-client>0:net-mgmt/py-prometheus-client@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>0:devel/py-prompt-toolkit@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}ptyprocess>0:sysutils/py-ptyprocess@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pycparser>0:devel/py-pycparser@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pyrsistent>0:devel/py-pyrsistent@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}rpy2>0:math/py-rpy2@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}scandir>0:sysutils/py-scandir@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}send2trash>0:deskutils/py-send2trash@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}simplegeneric>0:devel/py-simplegeneric@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}snowballstemmer>0:textproc/py-snowballstemmer@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-applehelp>0:textproc/py-sphinxcontrib-applehelp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-devhelp>0:textproc/py-sphinxcontrib-devhelp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-htmlhelp>0:textproc/py-sphinxcontrib-htmlhelp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-jsmath>0:textproc/py-sphinxcontrib-jsmath@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-qthelp>0:textproc/py-sphinxcontrib-qthelp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-serializinghtml>0:textproc/py-sphinxcontrib-serializinghtml@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-websupport>0:textproc/py-sphinxcontrib-websupport@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}terminado>0:net/py-terminado@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}testpath>0:devel/py-testpath@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}traitlets>0:devel/py-traitlets@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}tzlocal>0:devel/py-tzlocal@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}vcversioner>0:devel/py-vcversioner@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}wcwidth>0:devel/py-wcwidth@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}webencodings>0:converters/py-webencodings@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}widgetsnbextension>0:devel/py-widgetsnbextension@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}zipp>0:devel/py-zipp@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR}\
		fflas-ffpack-config:math/fflas-ffpack	\
		fricas>0:math/fricas		\
		gfan:math/gfan			\
		git:devel/git			\
		gp2c:math/gp2c			\
		jmol:science/jmol		\
		MathJax>0:www/mathjax		\
		maxima>0:math/maxima		\
		p5-Term-ReadLine-Gnu>0:devel/p5-Term-ReadLine-Gnu\
		palp>0:math/palp		\
		pandoc:textproc/hs-pandoc	\
		pari-elldata>0:math/pari_elldata\
		pari-galdata>0:math/pari_galdata\
		pari-galpol>0:math/pari_galpol	\
		pari-nftables>0:math/pari_nftables	\
		pari-seadata>0:math/pari_seadata\
		QuadraticSieve:math/flintqs	\
		rubiks>0:math/rubiks		\
		sympow:math/sympow		\
		tachyon:graphics/tachyon	\
		three.js>0:www/threejs		\
		yasm:devel/yasm			\
		pixz:archivers/pixz

USES=		autoreconf blaslapack:openblas compiler:c++11-lib fortran	\
		gettext gmake gnome iconv jpeg libtool localbase ncurses perl5	\
		pkgconfig python:3.7+ readline shebangfix sqlite tk xorg
USE_TEX=	latex:build pdftex:build tex:build
USE_XORG=	x11 xext xscrnsaver
USE_GNOME=	cairo glib20 pango
USE_PYTHON=	cython
USE_JAVA=	yes # for science/jmol

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}wheel-0.*

SHEBANG_FILES=	.
SHEBANG_LANG+=	dash
dash_OLD_CMD=	/bin/dash
dash_CMD=	${LOCALBASE}/bin/dash

DISABLE_BINUTILS=	yes

LIBS=		-lomp -pthread
.if !defined{WITH_DEBUG}
LDFLAGS+=	-s
.endif
BLDDIR=		${WRKDIR}/build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SAGE_PORT=yes CC=${CC} GCC=${CC} CXX=${CXX} AS=${AS} LD=${LD}	\
		SAGE_LOCAL=${PREFIX} SAGE_DESTDIR=${BLDDIR}/	\
		DESTDIR=${BLDDIR}/${PREFIX} PATCH=${LOCALBASE}/bin/gpatch
CONFIGURE_ARGS=	--with-system-gcc=force		\
		--with-system-python3=yes	\
		--with-python=${PYTHON_CMD}	\
		--enable-build-as-root		\
		--disable-download-from-upstream-url	\
		--localstatedir=/var
MAKE_ENV=	MAKE=${GMAKE} DESTDIR=${BLDDIR}
ALL_TARGET=	build
REINPLACE_ARGS=	-i ''
BINARY_ALIAS=	patch=${LOCALBASE}/bin/gpatch
OPTIONS_SUB=	yes
PLIST_SUB=	VER=${DISTVERSION}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

.include <bsd.port.pre.mk>

WSDIR=		${BLDDIR}${PREFIX}
SPKG_INST=	configure.ac configure build/sage_bootstrap/uninstall.py	\
		build/make/install src/bin/sage-env
PY2FIX=		bin lib/${PYTHON_VERSION}
DOC2FIX=	.pickle .doctree
SE2FIX=		^ECLDIR= ^SINGULAR MAXIMA_PREFIX
SHR2FIX=	GAP_ROOT_DIR PPLPY_DOCS SINGULARPATH
STG2FIX=	bin/sage-env-config	\
		share/jupyter/kernels/sagemath/kernel.json
BADLN=		kernels/sagemath/doc nbextensions/jsmol	\
		nbextensions/mathjax nbextensions/threejs
# External dependencies not yet handled by SageMath
# Note: do not use wheel from ports
PY_LIBS=	alabaster attrs babel backcall bleach certifi cffi cvxopt cycler	\
		cypari cysignals cython dateutil decorator defusedxml docutils	\
		entrypoints fpylll gmpy2 html5lib imagesize importlib_metadata ipykernel ipython	\
		ipython_genutils ipywidgets itsdangerous jedi jinja2 jsonschema jupyter_client	\
		jupyter_core kiwisolver markupsafe matplotlib mistune mpmath	\
		nbconvert nbformat networkx nose notebook numpy packaging pandocfilters	\
		parso pathpy pexpect pickleshare pillow pkgconfig pplpy		\
		prometheus_client prompt_toolkit psutil ptyprocess pybind11 pycparser pyparsing	\
		pygments pyrsistent pytz pyzmq requests rpy2 scandir scipy send2trash simplegeneric	\
		six snowballstemmer sphinx sphinxcontrib_applehelp sphinxcontrib_devhelp sphinxcontrib_htmlhelp sphinxcontrib_jsmath sphinxcontrib_qthelp sphinxcontrib_serializinghtml sphinxcontrib_websupport sympy terminado testpath tornado traitlets	\
		tzlocal vcversioner wcwidth webencodings widgetsnbextension zipp zope_interface
JS_LIBS=	jmol mathjax threejs
SPKGCM4=	e_antic ecl gap libhomfly linbox maxima pynac rubiks singular

post-patch:
	${CP} ${FILESDIR}/psutil__arch__bsd__freebsd_socks.c.patch	\
		${WRKSRC}/build/pkgs/psutil/patches/
.for sp in ${SPKGCM4}
	${CP} ${FILESDIR}/${sp}_spkg-configure.m4		\
		${WRKSRC}/build/pkgs/${sp}/spkg-configure.m4
.endfor
.for sp in ${PY_LIBS}
	${CP} ${FILESDIR}/py_libs_spkg-configure.m4		\
		${WRKSRC}/build/pkgs/${sp:C/pari2/pari/}/spkg-configure.m4
.endfor
#.for sp in ${PY_FILES}
#	${SED} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|' ${FILESDIR}/${sp}_spkg-configure.m4.in \
#		> ${WRKSRC}/build/pkgs/${sp}/spkg-configure.m4
#.endfor
.for sp in ${JS_LIBS}
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${FILESDIR}/${sp}_spkg-configure.m4.in \
		> ${WRKSRC}/build/pkgs/${sp}/spkg-configure.m4
.endfor

pre-configure:
	${REINPLACE_CMD} -e 's|SAGE_LOCAL="$$prefix"|SAGE_LOCAL="${WSDIR}"|'	\
		-e 's|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's|SAGE_LOCAL="@prefix@"|SAGE_LOCAL="${WSDIR}"|'	\
		${WRKSRC}/src/bin/sage-env-config.in
	${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|;s|%%LDFLAGS%%|${LDFLAGS}|'	\
		${WRKSRC}/build/pkgs/tachyon/patches/Make-arch.patch
	${REINPLACE_CMD} -e '/SUITESPARSE_INC_DIR/s|$${SAGE_LOCAL}/include|${LOCALBASE}/include/suitesparse|'\
		${WRKSRC}/build/pkgs/cvxopt/spkg-install.in
	${REINPLACE_CMD} -e 's|exec python3|exec ${PYTHON_CMD}|'		\
		-e 's|exec "$$SAGE_LOCAL"/bin/python3|exec ${PYTHON_CMD}|'	\
		${WRKSRC}/src/bin/sage
.for f in ${PY_LIBS}
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|;s|py_libs|${f}|'	\
		${WRKSRC}/build/pkgs/${f}/spkg-configure.m4
.endfor
	${REINPLACE_CMD} -e 's|import attrs|import attr|'	\
		${WRKSRC}/build/pkgs/attrs/spkg-configure.m4
	${REINPLACE_CMD} -e 's|import cypari|import cypari2|'	\
		${WRKSRC}/build/pkgs/cypari/spkg-configure.m4
	${REINPLACE_CMD} -e 's|import ipython|import IPython|'	\
		${WRKSRC}/build/pkgs/ipython/spkg-configure.m4
	${REINPLACE_CMD} -e 's|import pathpy|import path|'	\
		${WRKSRC}/build/pkgs/pathpy/spkg-configure.m4
	${REINPLACE_CMD} -e 's|import pillow|import PIL|'	\
		${WRKSRC}/build/pkgs/pillow/spkg-configure.m4
	${REINPLACE_CMD} -e 's|import pplpy|import ppl|'	\
		${WRKSRC}/build/pkgs/pplpy/spkg-configure.m4
	${REINPLACE_CMD} -e 's|import pyzmq|import zmq|'	\
		${WRKSRC}/build/pkgs/pyzmq/spkg-configure.m4
.for f in applehelp devhelp htmlhelp jsmath qthelp serializinghtml websupport
	${REINPLACE_CMD} -e 's|import sphinxcontrib_|import sphinxcontrib.|'	\
		${WRKSRC}/build/pkgs/sphinxcontrib_${f}/spkg-configure.m4
.endfor
	${REINPLACE_CMD} -e 's|import zope_interface|import zope.interface|'	\
		${WRKSRC}/build/pkgs/zope_interface/spkg-configure.m4
	${REINPLACE_CMD} -e '/GAP_ROOT=/s|$$SAGE_LOCAL|${LOCALBASE}|'	\
		${WRKSRC}/build/pkgs/gap_packages/spkg-install.in
	${REINPLACE_CMD} -e "/os.path.join/s|SAGE_LOCAL|'${LOCALBASE}'|"\
		${WRKSRC}/src/sage/libs/gap/util.pyx
	${REINPLACE_CMD} -e "/os.path.join(SAGE_LOCAL/s|SAGE_LOCAL|'${LOCALBASE}'|"	\
		${WRKSRC}/src/sage/env.py
	${REINPLACE_CMD} -e "/^library_dirs/s|SAGE_LOCAL|'${LOCALBASE}'|"	\
		${WRKSRC}/src/setup.py
.for f in ${SHR2FIX}
	${REINPLACE_CMD} -e "/${f}/s|SAGE_SHARE|'${LOCALBASE}/share/'|"	\
		${WRKSRC}/src/sage/env.py
.endfor
	${REINPLACE_CMD} -e "/JMOL_DIR/s|SAGE_SHARE|'${JAVASHAREDIR}'|"	\
			-e "/JMOL_DIR/s|jmol|classes|"			\
		${WRKSRC}/src/sage/env.py
	${REINPLACE_CMD} -e "/JSMOL_DIR/s|SAGE_SHARE|'${LOCALBASE}/www'|"	\
			-e "/JSMOL_DIR/s|jsmol|JSmol|"				\
		${WRKSRC}/src/sage/env.py
	${REINPLACE_CMD} -e "/MATHJAX_DIR/s|SAGE_SHARE|'${LOCALBASE}/www'|"	\
			-e "/MATHJAX_DIR/s|mathjax|MathJax|"			\
		${WRKSRC}/src/sage/env.py
	${REINPLACE_CMD} -e "/THREEJS_DIR/s|SAGE_SHARE|'${LOCALBASE}/www'|"	\
		${WRKSRC}/src/sage/env.py
.for f in ${SE2FIX}
	${REINPLACE_CMD} -e '/${f}/s|$$SAGE_LOCAL|${LOCALBASE}|'	\
		${WRKSRC}/src/bin/sage-env
.endfor
	${REINPLACE_CMD} -e '/LDFLAGS=/s|-rpath,$$SAGE_LOCAL|-rpath,${LOCALBASE}|'	\
		${WRKSRC}/src/bin/sage-env
.for f in ${SPKG_INST}
	${REINPLACE_CMD} -e 's|/var/lib/sage|/share/libdata/${PORTNAME}|'	\
		${WRKSRC}/${f}
.endfor
	(cd ${WRKSRC} && ./bootstrap)
	${MKDIR} ${BLDDIR}${PREFIX}/lib/pkgconfig	# Removed thereafter

post-build:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_CMD} doc)
.endif
.for d in ${PY2FIX}
	${FIND} ${WSDIR}/${d} -type f -exec ${GREP} -I -l "${WSDIR}/bin/python" {} \;	|\
	${XARGS} ${SED} -i "" -e 's|${WSDIR}/bin/pytho.*|${PYTHON_CMD}|'
.endfor
.for d in ${PY2FIX}
	${FIND} ${WSDIR}/${d} -type f -exec ${GREP} -I -l "/usr/bin/env python" {} \;	|\
	${XARGS} ${SED} -i "" -e 's|/usr/bin/env pytho.*|${PYTHON_CMD}|'
.endfor
	${FIND} ${BLDDIR}/${PYTHON_LIBDIR} -type d -name __pycache__ |	\
		${XARGS} ${RM} -r
.for f in ${DOC2FIX}
	${FIND} ${BLDDIR}${DOCSDIR} -type f -name "*${f}" | ${XARGS}	\
	${SED} -i "" -e 's|${BLDDIR}||g'
.endfor
.for f in ${STG2FIX}
	${SED} -i "" -e 's|${BLDDIR}||g' ${BLDDIR}${PREFIX}/${f}
.endfor
	${RM} ${BLDDIR}${PYTHON_CMD} ${BADLN:C|^|${BLDDIR}${PREFIX}/share/jupyter/|}
	${RM} -r ${BLDDIR}${PREFIX}/var
	${RM} ${BLDDIR}${PREFIX}/lib64 ${BLDDIR}${PREFIX}/lib/pkgconfig/blas.pc	\
		${BLDDIR}${PREFIX}/lib/pkgconfig/cblas.pc	\
		${BLDDIR}${PREFIX}/lib/pkgconfig/gsl.pc	\
		${BLDDIR}${PREFIX}/lib/pkgconfig/lapack.pc
	# Cannot use a package system for pip and setuptools
	${RM} ${BLDDIR}${PREFIX}/bin/easy_install* ${BLDDIR}${PREFIX}/bin/pip*
	${RM} -r ${BLDDIR}${PYTHON_SITELIBDIR}/pip-* ${BLDDIR}${PYTHON_SITELIBDIR}/pip/
	${RM} -r ${BLDDIR}${PYTHON_SITELIBDIR}/setuptools*		\
		${BLDDIR}${PYTHON_SITELIBDIR}/easy_install.py		\
		${BLDDIR}${PYTHON_SITELIBDIR}/pkg_resources		\
		${BLDDIR}${PYTHON_SITELIBDIR}/__pycache__/easy_install*
	# Remove CONFLICTS with lang/python3
	${RM} ${BLDDIR}${PREFIX}/bin/python ${BLDDIR}${PREFIX}/bin/python3
	${REINPLACE_CMD} -e '/exec/s|python3|${PYTHON_VERSION}|' ${BLDDIR}${PREFIX}/bin/sage
	# ${TRUE} because compilation of some .py fails: compileall.py -q to see errors
	(cd ${WSDIR} && (${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py	\
	 -d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} ||	\
	 ${TRUE}))
	${FIND} ${BLDDIR}${PREFIX} -name "*.bak" -delete
# See https://lists.freebsd.org/pipermail/freebsd-python/2020-June/020710.html
.if exists(${PYTHON_SITELIBDIR}/path.py-7.1.dist-info/WHEEL)
PLIST_SUB+=	EGG="@comment " WHEEL=""
.else
PLIST_SUB+=	EGG="" WHEEL="@comment "
.endif

do-install:
	cd "${BLDDIR}" && ${FIND} . | ${CPIO} -pduml ${STAGEDIR}
	# Remove bad links
	${LN} -sf ${DOCSDIR}	\
		${STAGEDIR}${PREFIX}/share/jupyter/kernels/sagemath/doc
	${LN} -sf ${LOCALBASE}/www/JSmol	\
		${STAGEDIR}${PREFIX}/share/jupyter/nbextensions/jsmol
	${LN} -sf ${LOCALBASE}/www/MathJax	\
		${STAGEDIR}${PREFIX}/share/jupyter/nbextensions/mathjax
	${LN} -sf ${LOCALBASE}/www/threejs	\
		${STAGEDIR}${PREFIX}/share/jupyter/nbextensions/threejs

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib64 ${STAGEDIR}${PREFIX}/libdata/pkgconfig/blas.pc	\
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/cblas.pc	\
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/gsl.pc	\
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/lapack.pc

.include <bsd.port.post.mk>
