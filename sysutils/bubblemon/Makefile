# New ports collection makefile for:	bubblemon
# Date created:				28 Aug 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	bubblemon
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.student.nada.kth.se/~d92-jwa/code/bubblemon/ \
		http://www.student.nada.kth.se/~d92-jwa/code/bubblemon/attic/

MAINTAINER=	rael@vectorstar.net
COMMENT=	Bubblemon is a system CPU and memory load monitor for the GNOME panel

LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack libpanel
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	bubblemon-gnome1.1
MANLANG=	"" hu sv

DOCS=	AUTHORS COPYING ChangeLog FAQ PROFILING TRANSLATIONS NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ;' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
