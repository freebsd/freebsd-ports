# New ports collection makefile for:	translator
# Date created:				24 Oct 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		translator
PORTVERSION=		0.1.0
CATEGORIES=		misc
MASTER_SITES=		http://jodrell.net/files/translator/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A GTK+ frontend to the Babelfish translation service

RUN_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
			${SITE_PERL}/${PERL_ARCH}/Gtk2/GladeXML.pm:${PORTSDIR}/x11-toolkits/p5-Glade2 \
			${SITE_PERL}/${PERL_ARCH}/Gnome2/GConf.pm:${PORTSDIR}/devel/p5-Gnome2-GConf \
			${SITE_PERL}/WWW/Babelfish.pm:${PORTSDIR}/www/p5-WWW-Babelfish

USE_X_PREFIX=		yes
USE_PERL5=		yes
NO_BUILD=		yes

.include <bsd.port.pre.mk>

HAVE_THREADS!=		${PERL} -mthreads -e '' >/dev/null 2>&1 && ${ECHO} 'yes' || true

.if ${PERL_LEVEL} < 500800 || empty(HAVE_THREADS)
IGNORE=			"Needs threaded perl 5.8.0 or higher, install lang/perl5.8 with threads support and try again"
.endif

post-patch:
	@${SED} -e \
		's|share/pixmaps|share/gnome/pixmaps| ; \
		 s|@PREFIX@|${PREFIX}|' \
		${WRKSRC}/translator.pl > ${WRKSRC}/translator

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/translator ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/translator.png ${PREFIX}/share/gnome/pixmaps
	${MKDIR} ${PREFIX}/share/translator
	${INSTALL_DATA} ${WRKSRC}/translator.glade ${PREFIX}/share/translator

.include <bsd.port.post.mk>
