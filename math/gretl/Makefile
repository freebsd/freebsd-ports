# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	0.991
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BROKEN=		"Does not build"

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	gtkextra:${PORTSDIR}/x11-toolkits/gtkextra \
		xml:${PORTSDIR}/textproc/libxml
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_X_PREFIX=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmake
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	gretl.1 gretl-config.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else
CONFIGURE_ARGS=	--disable-gnome
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/locale|\$$\(prefix\)/share/locale|g'

post-patch:
.for file in gui/gretl.c lib/src/graphing.c
	@${PERL} -pi -e "s,SIGCLD,SIGCHLD,g" ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s,-ldl,,g" ${WRKSRC}/lib/Makefile.in
.for file in gui/Makefile.in plugin/Makefile.in
	@${PERL} -pi -e "s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.post.mk>
