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
PORTREVISION=		5
CATEGORIES=		www # pita
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=		phoenix@freebsd.org # alane@fbsd and trevor@fbsd

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

NO_MTREE=		yes
WRKSRC=			${WRKDIR}/mozilla
LOCAL_PREFIX=		${PREFIX}/lib/${PORTNAME}
MAKE_ENV+=		XP_UNIX=1
MAKE_ARGS+=		XP_UNIX=1

.include <bsd.port.pre.mk>

.if !defined(PERL_LEVEL)
perl_major=${PERL_VERSION:C|^([1-9]+).*|\1|}
_perl_minor=00${PERL_VERSION:C|^([1-9]+)\.([0-9]+).*|\2|}
perl_minor=${_perl_minor:C|^.*(...)|\1|}
.if ${perl_minor} >= 100
perl_minor=${PERL_VERSION:C|^([1-9]+)\.([0-9][0-9][0-9]).*|\2|}
perl_patch=${PERL_VERSION:C|^.*(..)|\1|}
.else # ${perl_minor} < 100
_perl_patch=0${PERL_VERSION:C|^([1-9]+)\.([0-9]+)\.*|0|}
perl_patch=${_perl_patch:C|^.*(..)|\1|}
.endif # ${perl_minor} < 100
PERL_LEVEL=${perl_major}${perl_minor}${perl_patch}
.endif # !defined(PERL_LEVEL)

SITE_PERL?=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

.if ${OSVERSION} > 500038

BROKEN=	"on -CURRENT, can only be used with local files. You can run"
BROKEN+="make with -DNO_IGNORE to override this message"

.endif

.if ${PERL_LEVEL} < 500601
.undef NO_IGNORE
BROKEN=	"right now, we can only support the ports versions of Perl."
BROKEN+="We are working on the problem. Sorry for the inconvenience."
BROKEN+="If you have installed a Perl port, and are getting this message,"
BROKEN+="please make sure you have issued the command 'use.perl port'"

.endif # ${PERL_LEVEL} < 500601

pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "Extracting source (this takes a while) ..."
	@${ECHO_MSG}

post-extract::
	@${SED} -e 's|@CFLAGS@|${CFLAGS}|'		\
		-e 's|@LIBS@|${LIBS}|'			\
		-e 's|@X11BASE@|${X11BASE}|'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|'	\
		-e 's|@PREFIX@|${LOCAL_PREFIX}|'	\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig
	@${CAT} ${PKGMESSAGE} 2>/dev/null; sleep 5

# fix for Xft (thanks to marcus@)
post-patch:
	cd ${WRKSRC}/gfx/src/gtk;				\
	${REINPLACE_CMD} -e 's|X11/Xft/Xft\.h|X11/Xft/Xft2.h|g'	\
		nsDrawingSurfaceGTK.cpp	nsFontMetricsXft.h

post-install:
	@${RM} -f ${PREFIX}/bin/phoenix
	@${LN} -s ${LOCAL_PREFIX}/bin/phoenix \
		${PREFIX}/bin/phoenix
	@${RM} -f ${PREFIX}/bin/phoenix-config
	@${LN} -s ${LOCAL_PREFIX}/bin/mozilla-config \
		${PREFIX}/bin/phoenix-config
	@${CAT} ${PKGMESSAGE} 2>/dev/null; sleep 5
	@${RM} -fr ${LOCAL_PREFIX}/share
	@${RM} -fr ${LOCAL_PREFIX}/include

.include <bsd.port.post.mk>

#EOF
