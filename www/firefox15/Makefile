# ex:ts=8
#
# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		phoenix
PORTVERSION=		0.4
PORTREVISION=		2
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=		phoenix@geeksrus.net # alane@fbsd and trevor@fbsd

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2 \
		IDL.2:${PORTSDIR}/devel/ORBit \
		Xft2.2:${PORTSDIR}/x11-fonts/Xft

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2

USE_X_PREFIX=		yes

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_REINPLACE=		yes
HAS_CONFIGURE=		yes

USE_GNOMENG=		yes
USE_GNOME=		gtk12 orbit

CFLAGS+=		${PTHREAD_CFLAGS}
LIBS+=			${PTHREAD_LIBS}
.if defined(OPTIMIZE)
CFLAGS+=		-O2
.endif # defined(OPTIMIZE)

NO_MTREE=		yes
WRKSRC=			${WRKDIR}/mozilla
LOCAL_PREFIX=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

SITE_PERL?=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

PERL_MAJOR=${PERL_VER:C|^([1-9]+).*|\1|}
PERL_MINOR=${PERL_VER:C|^[1-9]+\.0*([1-9]+).*|\1|}

.if ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 8
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif # ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 8

.if ${OSVERSION} > 500038
BROKEN=	"on -CURRENT, can only be used with local files"
.endif

post-extract:
	${SED} -e 's|@CFLAGS@|${CFLAGS}|'		\
		-e 's|@LIBS@|${LIBS}|'			\
		-e 's|@X11BASE@|${X11BASE}|'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|'	\
		-e 's|@PREFIX@|${LOCAL_PREFIX}|'	\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig

# fix for Xft (thanks to marcus@)
post-patch:
	cd ${WRKSRC}/gfx/src/gtk;				\
	${REINPLACE_CMD} -e 's|X11/Xft/Xft\.h|X11/Xft/Xft2.h|g'	\
		nsDrawingSurfaceGTK.cpp	nsFontMetricsXft.h

post-install:
	${RM} -f ${PREFIX}/bin/phoenix
	${LN} -s ${LOCAL_PREFIX}/bin/phoenix \
		${PREFIX}/bin/phoenix
	${RM} -f ${PREFIX}/bin/phoenix-config
	${LN} -s ${LOCAL_PREFIX}/bin/mozilla-config \
		${PREFIX}/bin/phoenix-config

.include <bsd.port.post.mk>

#EOF
