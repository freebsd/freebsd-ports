# New ports collection makefile for:	TekNap napster client
# Date created:				6 Jul 2000
# Whom:					Carl Johan Madestrand
#
# $FreeBSD$
#

PORTNAME=	TekNap
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.teknap.com/pub/TekNap/ \
		ftp://ftp.bitchx.com/pub/TekNap/ \
		ftp://ukug.uk.freebsd.org/pub/lord_cj/

MAINTAINER=	cj@vallcom.net

.if defined(WITH_GTK)
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.endif

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
WRKSRC=		${WRKDIR}/TekNap
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if defined(WITH_GTK)
CONFIGURE_ARGS+= 	--with-gtk
.else
CONFIGURE_ARGS+= 	--without-gtk
.endif
CONFIGURE_ARGS+=	--exec-prefix="${PREFIX}/share" \
			--bindir="${PREFIX}/bin" \
			--datadir="${PREFIX}/share" \
			--libdir="${PREFIX}/share"

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.if !defined(WITH_GTK)
pre-extract:
	@${ECHO} "You can add hooks for GTK by defining WITH_GTK"
.endif

pre-configure:
	${PERL} -pi -e "s:-lc_r:-pthread:g" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/TekNap
	${TAR} --directory ${WRKSRC}/teknap-help -cf - . --exclude CVS | \
	${TAR} --directory ${PREFIX}/share/TekNap/help -xf -
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/TekNap
	@${ECHO}
	@${CAT} ${PKGDIR}/MESSAGE | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"
	@${ECHO}
.endif

.include <bsd.port.mk>
