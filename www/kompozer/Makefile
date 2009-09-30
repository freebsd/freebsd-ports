# New ports collection makefile for:	nvu
# Date created:		August 21, 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#    $MCom: ports/www/nvu/Makefile,v 1.5 2006/07/18 15:07:36 ahze Exp $
#

PORTNAME=	kompozer
DISTVERSION=	0.8a4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/current/${DISTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Complete Web Authoring Suite

WANT_GNOME=	yes
WANT_PERL=	yes
USE_BZIP2=	yes
USE_GECKO=	gecko
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/mozilla
MAKEFILE=	client.mk
ALL_TARGET=	build_all
MOZ_EXTENSIONS=	wallet,xml-rpc,xmlextras,pref,universalchardet,spellcheck
MOZ_OPTIONS=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
				--enable-application=composer \
				--enable-system-cairo
PORT_MOZCONFIG=	${WRKSRC}/composer/config/mozconfig.linux

DESKTOP_ENTRIES="Kompozer" "${COMMENT}" \
		"${PREFIX}/lib/kompozer/icons/mozicon50.xpm" "${PORTNAME}" \
		"Application;Network;" true

NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON_ia64=	does not build

.include <bsd.port.pre.mk>

.if ${ARCH}=="powerpc"
GECKO_PTHREAD_LIBS!=${CC} -dumpspecs | ${GREP} -m 1 '%{\!pg: %{pthread:' | ${SED
} -e 's|^.*%{\!pg: %{pthread:|| ; s|}.*$$||' || ${TRUE}
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
		${WRKSRC}/storage/build/Makefile.in
	@${RM} -f ${WRKSRC}/config.status ${WRKSRC}/config.cache
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/Makefile.in
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/gnome/Makefile.in

.include <bsd.port.post.mk>
