# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution
PORTVERSION=	0.99.0
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/evolution

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	bonobo_conf.0:${PORTSDIR}/devel/bonobo-conf
#ldap.1:${PORTSDIR}/net/openldap <- avoid extra dependency until
#						   it actually works

#BROKEN=		"Out of sync with latest gal"

USE_GMAKE=	yes
USE_BISON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db3-libs=${LOCALBASE}/lib \
		--with-html-dir=${PREFIX}/share/gnome/html
# --with-pisock=${LOCALBASE}/pilot --enable-pilot-conduits=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
	@find ${WRKSRC} -type f -name "*.[ch]" | xargs ${GREP} -l '[^g]iconv.h' | \
		xargs ${PERL} -pi -e 's|(["<])iconv.h|\1giconv.h|g'
	@find ${WRKSRC} -type f -name "*.[ch]" | xargs ${GREP} -l '<db.h>' | \
		xargs ${PERL} -pi -e 's|<db.h>|<db3/db.h>|g'
	@find ${WRKSRC} -type f -name "*.[ch]" | xargs ${GREP} -l 'wrong DB3' | \
		xargs ${PERL} -pi -e 's|.*wrong DB3.*||'

post-install:
	@find ${PREFIX}/share/gnome/evolution/default_user -type f | \
		xargs ${CHMOD} 644

.include <bsd.port.mk>
