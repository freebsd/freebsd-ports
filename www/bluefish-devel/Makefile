# New ports collection makefile for:   bluefish
# Date created:			23 January 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	bluefish
PORTVERSION=	0.9.20030223
CATEGORIES=	www editors
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/${DOWNLOAD}/ \
		ftp://bluefish.advancecreations.com/pub/bluefish/${DOWNLOAD}/ \
		http://bluefish.mrball.net/${DOWNLOAD}/ \
		ftp://ftp.ratisbona.com/pub/bluefish/${DOWNLOAD}/ \
		http://bluefish.shellhung.org/${DOWNLOAD}/
DISTNAME=	${PORTNAME}-gtk2port-2003-02-23
EXTRACT_SUFX=	.tgz

MAINTAINER=	einekoai@chello.nl
COMMENT=	HTML editor designed for the experienced web designer

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		pcre.0:${PORTSDIR}/devel/pcre \
		aspell.15:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	weblint:${PORTSDIR}/www/weblint

DOWNLOAD=	snapshots
WRKSRC=		${WRKDIR}/bluefish-gtk2
NO_LATEST_LINK=	yes
#USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehier
USE_PERL5_BUILD=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gnome2-menu=/${PREFIX}/share/gnome/apps/Applications

.include <bsd.port.pre.mk>

# Turns debugging output on
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debugging-output
.endif

pre-everything::
.if !defined(WITH_DEBUG)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_DEBUG=yes for debug support"
.endif

.include <bsd.port.post.mk>
