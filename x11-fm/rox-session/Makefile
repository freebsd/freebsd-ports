# New ports collection makefile for:	rox-session
# Date created:        11 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox-session
PORTVERSION=	0.1.11
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=	ROX-Session
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/Choices:${PORTSDIR}/x11-fm/rox-base \
		${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer

USE_GLIB=	yes
USE_GTK=	yes

post-extract:
	# Hopefully gtk-config and glib-config will become
	# configurable, so don't bother to add patch-* files

	${PERL} -pi -e "s/gtk-config/gtk12-config/g" \
		${WRKSRC}/src/Makefile.in
	${PERL} -pi -e "s/glib-config/glib12-config/g" \
		${WRKSRC}/src/configure

do-build:
	# Run the custom build procedure
	cd ${WRKSRC} && GTK_CONFIG=${GTK_CONFIG} GLIB_CONFIG=${GLIB_CONFIG} ./AppRun --compile

do-install:
	${MKDIR} ${PREFIX}/apps/ROX-Session
	cd ${WRKSRC} && ${CP} -r AppIcon.xpm AppMenu AppRun FreeBSD-ix86 Help Login MakeDefault.sh Setup Styles ${PREFIX}/apps/ROX-Session
	${CAT} ${FILESDIR}/rox-session | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${PREFIX}/bin/rox-session
	${CHMOD} 775 ${PREFIX}/bin/rox-session

.include <bsd.port.mk>
