# ex:ts=8
# Ports collection makefile for:	gsubedit
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsubedit
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnome
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,Bison ,Bison,g" ${WRKSRC}/configure
	@${PERL} -pi -e "s,doc/,share/doc/,g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
