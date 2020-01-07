# Created by: SimaMoto,RyoTa <liangtai.s4@gmail.com>
# $FreeBSD$

PORTNAME=	gimp-help
PORTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES?=	misc graphics
MASTER_SITES=	http://gimp.mirrors.hoobly.com/pub/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	gimp/help
PKGNAMEPREFIX?=	${DOCLANG}-
PKGNAMESUFFIX=	-html

MAINTAINER=	liangtai.s16@gmail.com
COMMENT?=	GIMP User Manual in English

LICENSE=	GFDL

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-08

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:textproc/py-libxml2@${PY_FLAVOR} \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl

USES=		gettext-tools gmake gnome perl5 pkgconfig python:2.7 shebangfix \
		tar:bzip2
USE_GNOME=	libxslt:build
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gimp
CONFIGURE_ENV=	ALL_LINGUAS=${DOCLANG}

DOCLANG?=	en

PORTDATA=	*
DATADIR=	${PREFIX}/share/gimp

MAKE_JOBS_UNSAFE=	yes

SHEBANG_FILES=	tools/xml2po.py

post-patch:
# Install to the same directory as when configuring --with-gimp
	${REINPLACE_CMD} '/gimpdatadir=.*\/2.0/s,/2\.0,,' \
		${WRKSRC}/configure
.if ${DOCLANG:Mru}
	${REINPLACE_CMD} -e '/glossary\.xml:1596/{; n; n; s/xref/link/g; }' \
		${WRKSRC}/po/ru/glossary.po
.endif

.include <bsd.port.mk>
