# New ports collection makefile for:	gtktalog
# Date created:				20 Mar 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	gtktalog
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}.pkg/${PORTVERSION}

MAINTAINER=	rael@vectorstar.net
COMMENT=	GTKtalog is a tool to make disk catalogs

USE_GNOME=	gnomeprefix gnomelibs
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

MAN1=		gtktalog.1

DOCS=	AUTHORS BUGS ChangeLog NEWS README TODO

CONFIGURE_ENV=	XGETTEXT=${LOCALBASE}/bin/xgettext

post-patch:
	@${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@" ${WRKSRC}/configure
	@${REINPLACE_CMD} -E "s@^(Applicationsdir = ).*@\1${PREFIX}/share/gnome/apps/Applications@" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E "s@^(localedir = ).*@\1${PREFIX}/share/locale@" \
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -E "s@^(gtktalog_helpdir = ).*@\1${PREFIX}/share/gnome/help/gtktalog/C@" ${WRKSRC}/Docs/C/Makefile.in
	@${REINPLACE_CMD} -E "s@^(gtktalog_helpdir = ).*@\1${PREFIX}/share/gnome/help/gtktalog/fr@" ${WRKSRC}/Docs/fr/Makefile.in
	@${REINPLACE_CMD} -E "s@^(MountPoint ).*@\1/cdrom@" \
		${WRKSRC}/src/gtktalog/gtktalog.cf.in.in

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gtktalog/*/images 2>/dev/null || ${TRUE}
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
