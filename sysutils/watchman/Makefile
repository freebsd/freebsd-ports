# Created by: Jin-Sih, Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	watchman
PORTVERSION=	3.0.0
CATEGORIES=	sysutils

MAINTAINER=	linpct@gmail.com
COMMENT=	File alteration monitoring service

LICENSE=	APACHE20

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_TAGNAME=	v${PORTVERSION}

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
	@${REINPLACE_CMD} -e '/timestamp=/s,%ld,%d,' ${WRKSRC}/root.c

.include <bsd.port.mk>
