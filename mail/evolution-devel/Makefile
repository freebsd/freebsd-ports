# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.sleepycat.com/update/3.1.17/ \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/evolution
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		db-3.1.17.tar.gz

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	bonobo_conf.0:${PORTSDIR}/devel/bonobo-conf \
		nss3.1:${PORTSDIR}/security/nss
#		ldap.2:${PORTSDIR}/net/openldap2
RUN_DEPENDS=	gnome-spell-component:${PORTSDIR}/textproc/gnomespell
.if !defined(WITHOUT_PILOT)
BUILD_DEPENDS+=	${X11BASE}/lib/gnome-pilot/conduits/libemail_conduit.so:${PORTSDIR}/palm/gnomepilot-conduits
RUN_DEPENDS+=	${X11BASE}/lib/gnome-pilot/conduits/libemail_conduit.so:${PORTSDIR}/palm/gnomepilot-conduits
.endif

#BROKEN=		"Out of sync with latest gal"

USE_GMAKE=	yes
USE_BISON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db3-libs=${DB3_WRKSRC} \
		--with-db3-includes=${DB3_WRKSRC} \
		--with-html-dir=${PREFIX}/share/gnome/html \
		--with-nspr-includes=${LOCALBASE}/include/nspr \
		--with-nspr-libs=${LOCALBASE}/lib \
		--with-nss-includes=${LOCALBASE}/include/nss/security \
		--with-nss-libs=${LOCALBASE}/lib
#		--with-openldap=${LOCALBASE}
.if !defined(WITHOUT_PILOT)
CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE} \
			--enable-pilot-conduits=yes
PLIST_SUB=	PILOT:=""
.else
PLIST_SUB=	PILOT:="@comment "
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${DB3_WRKSRC} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB+=	VERSION=${PORTVERSION}

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

# DB3 stuff. Ugly, I know, but that's life.
DB3_WRKSRC=	${WRKDIR}/db-3.1.17/build_unix
DB3_CONFIGURE_SCRIPT=	../dist/configure
DB3_CONFIGURE_ARGS=	--enable-compat185 \
			--enable-dump185 --enable-cxx \
			--enable-static \
			--disable-dynamic \
			--prefix=${PREFIX} \
			--includedir=${PREFIX}/include/db3 \
			--target=${ARCH}-unknown-freebsd${OSREL}

pre-configure:
	@(cd ${DB3_WRKSRC} && \
	    ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${DB3_CONFIGURE_ENV} ./${DB3_CONFIGURE_SCRIPT} ${DB3_CONFIGURE_ARGS})
	@(cd ${DB3_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@${RM} -f ${DB3_WRKSRC}/db3
	@${LN} -s . ${DB3_WRKSRC}/db3
# End of the DB3 stuff

post-install:
	@find ${PREFIX}/share/gnome/evolution/default_user -type f | \
		xargs ${CHMOD} 644

.include <bsd.port.mk>
