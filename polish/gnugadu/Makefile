# Ports collection makefile for: gnugadu
# Date created:		23 dec 2001
# Whom: 		doc@lublin.t1.pl
#
# $FreeBSD$
#

PORTNAME=	gnugadu
PORTVERSION=	0.2.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.slackware.pl/gg/
DISTNAME=	gg-${PORTVERSION}

MAINTAINER=	doc@lublin.t1.pl

WRKSRC=	${WRKDIR}/gg-${PORTVERSION}

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
PKGNAMESUFFIX=	-esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

pre-everything::
.if defined(WITH_GNOME)
CONFIGURE_ARGS+=	--enable-gnome
USE_GNOME=	yes
.else
	@${ECHO_MSG}	"Define WITH_GNOME to include GNOME support"
.endif

.if defined(WITH_DOCKAPP)
CONFIGURE_ARGS+=	--enable-dockapp
.else
	@${ECHO_MSG}	"Define WITH_DOCKAPP to include WindowMaker support"
.endif

post-patch:
	@${PERL} -pi -e 's,CFLAGS =, CFLAGS += \@GTK_CFLAGS\@,; \
		s,GTK_ CFLAGS,GTK_CFLAGS,' ${WRKSRC}/Makefile.in \
		${WRKSRC}/src/Makefile.in
	@${PERL} -pi -e 's,-O2,,; s,gtk-config,${GTK_CONFIG},' \
		${WRKSRC}/configure

post-install:
	     strip ${PREFIX}/bin/gg

.include <bsd.port.post.mk>
