# Created by: Jin-Sih, Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	watchman
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	linpct@gmail.com
COMMENT=	File alteration monitoring service

LICENSE=	APACHE20

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

USES=		autoreconf gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_HAVE_ARC=false
CONFIGURE_ARGS=	--with-pcre

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--disable-silent-rules
.endif

CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/watchman
PORTDOCS=	README.markdown

post-patch:
	@${REINPLACE_CMD} -e '/^docdir = /d' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
