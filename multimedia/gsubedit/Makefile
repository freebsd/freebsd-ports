# ex:ts=8
# Ports collection makefile for:	gsubedit
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	GSubEdit
PORTVERSION=	0.4.p1
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME Subtitle Editor is a tool for editing/converting video subtitles

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext

post-patch:
# CFLAGS safeness
# pthread safeness
	@${REINPLACE_CMD} -E -e 's|-g -O2||; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/src/Makefile.in
# prefix safeness for docs
	@${REINPLACE_CMD} -E -e \
		's|^(gsubeditdocdir[[:space:]]*=).*$$|\1${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
# prefix safeness for pixmaps
	@${REINPLACE_CMD} -E -e \
		's|^(packagepixmapsdir[[:space:]]*=).*$$|\1share/gnome/pixmaps/\$${PACKAGE}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
# install neither charset.alias nor locale.alias. Therefore, do not
# build distfiles' gettext
	@${REINPLACE_CMD} -E -e \
		's|^(SUBDIRS[[:space:]]*=.+)intl|\1|' \
		${WRKSRC}/Makefile.in
# do not install docs
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e \
		's|^(install-data-am.+)install-gsubeditdocDATA|\1|'
		\ ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
