# Ports collection makefile for: gnugadu
# Date created:		23 dec 2001
# Whom: 		doc@lublin.t1.pl
#
# $FreeBSD$
#

PORTNAME=	gnugadu
PORTVERSION=	0.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.slackware.pl/gg/
DISTNAME=	gg-${PORTVERSION}

MAINTAINER=	doc@lublin.t1.pl

WRKSRC=	${WRKDIR}/gg-${PORTVERSION}

USE_GMAKE=	yes
USE_GTK=	yes
WANT_ESOUND=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
.else
CONFIGURE_ARGS+=	--disable-esd
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
