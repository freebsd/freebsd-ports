# New ports collection makefile for:    gutenbook
# Date created:                 21 December 2000
# Whom:                         Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	gutenbook
PORTVERSION=	0.1.10
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.gutenbook.org/download/

MAINTAINER=	jeremy@external.org
COMMENT=	GTK+ based reader for Project Gutenberg Etexts

RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		${site_perl}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${site_perl}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${site_perl}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${site_perl}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk \
		${site_perl}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${site_perl}/URI/URL.pm:${PORTSDIR}/net/p5-URI

site_perl=	${SITE_PERL}

USE_GNOME=	gtk12
NO_BUILD=	yes

MODULES=	Etext.pm File.pm Index.pm Network.pm PropList.pm

post-patch:
	@${SED} "s#%%LOCALBASE%%#${LOCALBASE}#g" ${WRKSRC}/PGB.pm > ${WRKSRC}/tmp
	@${MV} ${WRKSRC}/tmp ${WRKSRC}/PGB.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gutenbook ${PREFIX}/bin/gutenbook
	${INSTALL_SCRIPT} ${WRKSRC}/PGB.pm ${site_perl}/PGB.pm
	@${MKDIR} ${site_perl}/PGB
.for module in ${MODULES}
	${INSTALL_SCRIPT} ${WRKSRC}/PGB/${module} \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/PGB
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gutenbook
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${PREFIX}/share/doc/gutenbook
	${INSTALL_DATA} ${WRKSRC}/gutenbook.spec ${PREFIX}/share/doc/gutenbook
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE} | ${SED} 's#/usr/local#${PREFIX}#g'
.endif

.include <bsd.port.mk>
