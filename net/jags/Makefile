# New ports collection makefile for:	jags
# Date created:				Thu Jul  5 17:13:11 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	jags
PORTVERSION=	0.20.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://sumpan.campus.luth.se/software/jags/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	JAGS - Just Another GTK+ Samba Client

USE_GMAKE=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes

pre-patch:
	@${PERL} -pi.fbsd -e 's@/usr/local/share/jags/@${PREFIX}/share/jags/@g' \
		${WRKSRC}/src/jagsconfig.cpp
	@${PERL} -pi.fbsd -e 's@/usr/local/share/jags/pixmaps/@${PREFIX}/share/jags/pixmaps/@g' \
		${WRKSRC}/src/gtk_common.cpp

.include <bsd.port.mk>
