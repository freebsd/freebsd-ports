# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution
PORTVERSION=	1.3.3
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://people.FreeBSD.org/~sobomax/:local
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.3 \
			sobomax/:local
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		db-3.1.17${EXTRACT_SUFX}:local
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated mail, calendar and address book distributed suite

LIB_DEPENDS=	nss3.1:${PORTSDIR}/security/nss \
		soup-2.0.0:${PORTSDIR}/devel/libsoup \
		gtkhtml-3.0.1:${PORTSDIR}/www/gtkhtml3

.if defined(WITH_LDAP)
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap20
.endif
RUN_DEPENDS=	${X11BASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnomespell-devel
.if !defined(WITHOUT_PILOT)
LIB_DEPENDS+=	gpilotdconduit.2:${PORTSDIR}/palm/gnomepilot2
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
USE_REINPLACE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db3-libs=${DB3_WRKSRC} \
		--with-db3-includes=${DB3_WRKSRC} \
		--with-nspr-includes=${LOCALBASE}/include/nspr \
		--with-nspr-libs=${LOCALBASE}/lib \
		--with-nss-includes=${LOCALBASE}/include/nss/nss \
		--with-nss-libs=${LOCALBASE}/lib

.if defined(WITH_LDAP)
CONFIGURE_ARGS+= --with-openldap=${LOCALBASE}
.endif

.if !defined(WITHOUT_PILOT)
CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE} \
			--enable-pilot-conduits=yes
PLIST_SUB=	PILOT:=""
.else
PLIST_SUB=	PILOT:="@comment "
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${DB3_WRKSRC} -I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"

PLIST_SUB+=	VERSION="1.3"

#MAN1=		evolution.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" | xargs ${GREP} -l '<db.h>' | \
		${XARGS} ${REINPLACE_CMD} -e 's|<db.h>|<db3/db.h>|g'

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
	@${FIND} ${PREFIX}/share/gnome/evolution/default_user -type f | \
		${XARGS} ${CHMOD} 644

.include <bsd.port.mk>
