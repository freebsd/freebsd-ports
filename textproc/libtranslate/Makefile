# New ports collection makefile for:	libtranslate
# Date created:			15 Jan 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		libtranslate
PORTVERSION=		0.99
PORTREVISION=		6
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} # May append to this

PATCHFILES=		libtranslate-0.99-services.diff libtranslate-0.99-postmarker.diff
PATCH_SITES=		${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A natural language translation library

USE_GNOME=		glib20 gnomehack intlhack
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LDCONFIG=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=		--with-html-dir=${PREFIX}/share/doc
MAKE_JOBS_SAFE=		yes

OPTIONS=		GENERIC "generic module" on \
			TALKFILTERS "talkfilters module" on

MAN1=			translate.1

post-patch::
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|'	\
		-e 's|libsoup-2.2|libsoup-2.4|g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GENERIC)
CONFIGURE_ARGS+=	--disable-generic
PLIST_SUB+=		GENERIC="@comment "
.else
PLIST_SUB+=		GENERIC=""
USE_GNOME+=		libxml2
LIB_DEPENDS+=		soup-2.4:${PORTSDIR}/devel/libsoup
MAN5+=			services.xml.5
CPPFLAGS+=		-DHAVE_LIBSOUP24
DISTFILES+=		libtranslate-0.99-libsoup24.diff
EXTRACT_ONLY=		${DISTFILES:M*tar.*}
# This patching needs to happen AFTER the stock patches were applied:
post-patch::
	${SED} s,SOUP_MESSAGE_RESPONSE_,trans_SOUP_MESSAGE_RESPONSE_,g	\
	    ${DISTDIR}/libtranslate-0.99-libsoup24.diff \
		| ${PATCH} -d ${WRKSRC} -p1
.endif

.if defined(WITHOUT_TALKFILTERS)
CONFIGURE_ARGS+=	--disable-talkfilters
PLIST_SUB+=		TALKFILTERS="@comment "
.else
PLIST_SUB+=		TALKFILTERS=""
LIB_DEPENDS+=		talkfilters:${PORTSDIR}/misc/talkfilters
.endif

.include <bsd.port.post.mk>
