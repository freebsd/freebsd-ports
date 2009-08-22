# New ports collection makefile for:   GnoeMoe
# Date created:        11 January 2005
# Whom:                Jesse van den Kieboom <jesse@icecrew.nl>
#
# $FreeBSD$
#

PORTNAME=	gnoemoe
PORTVERSION=	0.8.1
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	http://www.icecrew.nl/software/gnoemoe/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome MOO Client

USE_RUBY=	yes
USE_RUBY_FEATURES=	ruby18

USE_GNOME=	gnomeprefix gtksourceview libglade2 libgnomeui vte
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/src/Makefile.in

post-install:
	update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
