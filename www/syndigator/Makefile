# ex:ts=8
# Ports collection Makefile for: 	syndigator
# Date created:			Apr 20, 2004
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	syndigator
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RSS feed reader based on Gtk2

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/${PERL_ARCH}/Gnome2.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/Html2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2-Html2 \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

WRKSRC=		${WRKDIR}/${DISTNAME:S/.1-/-/}
USE_X_PREFIX=	yes
USE_PERL5=	yes
MAKE_ENV=	SITE_PERL=${SITE_PERL} \
		GNOMEDIR=${X11BASE}/share/gnome

post-install:
	@${ECHO_CMD} "@cwd ${LOCALBASE}" >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/syndigator ! -type d | \
		${SED} 's,^${LOCALBASE}/,,' >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/syndigator -type d | ${SORT} -r | \
		${SED} 's,^${LOCALBASE}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
