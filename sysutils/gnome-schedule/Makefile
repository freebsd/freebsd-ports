# New ports collection makefile for:	gnome-schedule
# Date created:		2004-11-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-schedule/Makefile,v 1.5 2007/09/10 06:20:14 mezz Exp $
#

PORTNAME=	gnome-schedule
PORTVERSION=	0.9.0
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME GUI for configuring a users crontab

BUILD_DEPENDS=	yelp:${PORTSDIR}/x11/yelp
RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomeprefix pygnome2
GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share

.include <bsd.port.pre.mk>

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|pixmaps doc po|pixmaps po|g' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|gnome-schedule-$$(VERSION)|gnome-schedule|' \
		${WRKSRC}/doc/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|/usr/share/icons|${LOCALBASE}/share/icons|; \
		s|@prefix@/share|${DATADIR}|; \
		s|/usr/local/share/|${DATADIR}|; \
		s|/usr/share/|${DATADIR}|; \
		s|/usr/bin/gnome-help|${LOCALBASE}/bin/gnome-help|; \
		s|$$(prefix)/share/|$$(datadir)/|' \
			${WRKSRC}/src/*.* ${WRKSRC}/Makefile.in \
			${WRKSRC}/pixmaps/Makefile.in

.include <bsd.port.post.mk>
