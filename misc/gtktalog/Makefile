# New ports collection makefile for:	gtktalog
# Date created:				20 Mar 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	gtktalog
PORTVERSION=	0.99.20
CATEGORIES=	misc
MASTER_SITES=	http://savannah.nongnu.org/download/gtktalog/gtktalog/sources/

MAINTAINER=	rael@vectorstar.net

USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomelibs
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_PERL5=	yes

MAN1=		gtktalog.1

DOCS=	AUTHORS BUGS COPYING ChangeLog NEWS README TODO

post-patch:
	${PERL} -pi -e "s@^(Applicationsdir = ).*@\1${PREFIX}/share/gnome/apps/Applications@" ${WRKSRC}/Makefile.in
	${PERL} -pi -e "s@^(localedir = ).*@\1${PREFIX}/share/locale@" \
		${WRKSRC}/po/Makefile.in.in
	${PERL} -pi -e "s@^(gtktalog_helpdir = ).*@\1${PREFIX}/share/gnome/help/gtktalog/C@" ${WRKSRC}/Docs/C/Makefile.in
	${PERL} -pi -e "s@^(gtktalog_helpdir = ).*@\1${PREFIX}/share/gnome/help/gtktalog/fr@" ${WRKSRC}/Docs/fr/Makefile.in
	${PERL} -pi -e "s@^(MountPoint ).*@\1/cdrom@" \
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
