# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://people.FreeBSD.org/~sobomax/:local
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.4 \
			sobomax/:local
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		db-3.1.17${EXTRACT_SUFX}:local
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated mail, calendar and address book distributed suite

RUN_DEPENDS=	${X11BASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnomespell

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnometarget gtkhtml3
USE_REINPLACE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db3-libs=${DB3_WRKSRC} \
		--with-db3-includes=${DB3_WRKSRC} \
		--enable-nss=no \
		--enable-openssl=yes \
		--with-krb5=/usr
CONFIGURE_ENV=	CPPFLAGS="-I${DB3_WRKSRC} -I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS}"
LDFLAGS+=	-L${LOCALBASE}/lib

EVO_VERSION=	1.4
PLIST_SUB=	VERSION=${EVO_VERSION}
PKGINSTALL=	${WRKDIR}/pkg-install

OPTIONS=	PILOT "Enable Palm Pilot sync support" off \
		LDAP "Enable LDAP support" on

.include <bsd.port.pre.mk>

.if defined(WITH_PILOT)
LIB_DEPENDS+=	gpilotdconduit.2:${PORTSDIR}/palm/gnomepilot2
CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE} \
			--enable-pilot-conduits=yes
PLIST_SUB+=	PILOT:=""
.else
PLIST_SUB+=	PILOT:="@comment "
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-openldap=no
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--with-pic
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" | ${XARGS} ${GREP} -l '<db.h>' | \
		${XARGS} ${REINPLACE_CMD} -e 's|<db.h>|<db3/db.h>|g'
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${DB3_WRKSRC}/${DB3_CONFIGURE_SCRIPT}

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
	@${FIND} ${PREFIX}/share/gnome/evolution/${EVO_VERSION}/default_user \
		-type f | ${XARGS} ${CHMOD} u+w

.include <bsd.port.post.mk>
