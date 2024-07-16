PORTNAME=	gimp-help
DISTVERSION=	2.10.34
PORTREVISION?=	0
CATEGORIES?=	misc graphics
MASTER_SITES=	https://download.gimp.org/pub/%SUBDIR%/ \
		https://ftp.gwdg.de/pub/misc/grafik/%SUBDIR%/ \
		https://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	gimp/help
PKGNAMEPREFIX?=	${DOCLANG}-
PKGNAMESUFFIX=	-html

MAINTAINER?=	liangtai.s16@gmail.com
COMMENT?=	GIMP User Manual in English
WWW=		https://docs.gimp.org/

LICENSE=	GFDL

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2@${PY_FLAVOR} \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl

USES=		gettext-tools gmake gnome perl5 pkgconfig python:3.8+,build shebangfix \
		tar:bzip2
USE_GNOME=	intltool:build libxslt:build
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gimp
CONFIGURE_ENV=	ALL_LINGUAS="${DOCLANG}" QUICKREFERENCE_ALL_LINGUAS="${DOCLANG}"

DOCLANG?=	en

PORTDATA=	*
DATADIR=	${PREFIX}/share/gimp

MAKE_JOBS_UNSAFE=	yes

SHEBANG_FILES=	tools/xml2po.py

OPTIONS_DEFINE=		QUICKREFERENCE
OPTIONS_DEFAULT=	QUICKREFERENCE

QUICKREFERENCE_DESC=		Generate GIMP Quickreference PDF (keys bindings)
QUICKREFERENCE_USE=		gnome=librsvg2:build
QUICKREFERENCE_CONFIGURE_OFF=	ac_cv_path_SVG2PDF=

post-patch:
# Install to the same directory as when configuring --with-gimp
	${REINPLACE_CMD} '/gimpdatadir=.*\/2.0/s,/2\.0,,' \
		${WRKSRC}/configure

.include <bsd.port.mk>
