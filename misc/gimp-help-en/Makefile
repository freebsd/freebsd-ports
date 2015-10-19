# Created by: SimaMoto,RyoTa <liangtai.s4@gmail.com>
# $FreeBSD$

PORTNAME=	gimp-help
PORTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES?=	misc graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	gimp/help
PKGNAMEPREFIX?=	${DOCLANG}-
PKGNAMESUFFIX=	-html

MAINTAINER=	liangtai.s16@gmail.com
COMMENT?=	GIMP User Manual in English

LICENSE=	GFDL

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2 \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl

USES=		gettext-tools gmake perl5 pkgconfig python:2 shebangfix tar:bzip2
USE_GNOME=	libxslt:build
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gimp
CONFIGURE_ENV=	ALL_LINGUAS=${DOCLANG}

DOCLANG?=	en

PORTDATA=	*
DATADIR=	${PREFIX}/share/gimp

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
