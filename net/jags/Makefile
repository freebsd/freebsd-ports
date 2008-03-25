# New ports collection makefile for:	jags
# Date created:				Thu Jul  5 17:13:11 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	jags
PORTVERSION=	0.20.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://sumpan.campus.luth.se/software/jags/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JAGS - Just Another GTK+ Samba Client

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_XORG=	xpm
USE_GNOME=	gtk12
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Broken with gcc 4.2
.endif

pre-patch:
	@${PERL} -pi.fbsd -e 's@/usr/local/share/jags/@${PREFIX}/share/jags/@g' \
		${WRKSRC}/src/jagsconfig.cpp
	@${PERL} -pi.fbsd -e 's@/usr/local/share/jags/pixmaps/@${PREFIX}/share/jags/pixmaps/@g' \
		${WRKSRC}/src/gtk_common.cpp

.include <bsd.port.post.mk>
