# Created by: lance@evitel.net
# $FreeBSD$

PORTNAME=	gnu-radius
PORTVERSION=	1.6.1
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	GNU/radius
DISTNAME=	radius-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU RADIUS server

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		cpe gmake libtool
USE_RC_SUBR=	radiusd
USE_SUBMAKE=	yes
USE_LDCONFIG=	yes
CPE_PRODUCT=	radius
CPE_VENDOR=	gnu

CONFLICTS=	freeradius-0.* openradius-0.* radiusd-cistron-1.*
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	PORTVERSION=${PORTVERSION}
DATADIR=	${PREFIX}/share/radius

INFO=		radius

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR="${.CURDIR}" \
		MKDIR="${MKDIR}"
CONFIGURE_ARGS+=--with-include-path="${LOCALBASE}/include/" \
		--with-lib-path="${LOCALBASE}/lib/"

OPTIONS_DEFINE=	CLIENT MYSQL PGSQL EXAMPLES DBM SNMP EMACS PAM NLS
OPTIONS_DEFAULT=MYSQL
OPTIONS_SUB=	yes
CLIENT_DESC=	Build client
EMACS_DESC=	Install Emacs dotfiles

SNMP_CONFIGURE_ENABLE=		snmp
CLIENT_CONFIGURE_ENABLE=	client
CLIENT_LIB_DEPENDS=		libguile.so:lang/guile
CLIENT_CONFIGURE_OFF=		--without-guile
MYSQL_USES=			mysql
MYSQL_CONFIGURE_WITH=		mysql
PGSQL_USES=			pgsql
PGSQL_CONFIGURE_WITH=		postgres
DBM_CONFIGURE_ENABLE=		dbm=ndbm
EMACS_USES=			emacs
EMACS_CONFIGURE_WITH=		lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}
EMACS_NO_DEPENDS=		yes
NLS_USES=			gettext
NLS_CONFIGURE_OFF=		--disable-nls
PAM_CONFIGURE_ENABLE=		pam

post-patch:
	${REINPLACE_CMD} -e 's|extern unsigned scheme_gc_interval;||g' \
		${WRKSRC}/include/radiusd.h
	${REINPLACE_CMD} -e 's|int getline|ssize_t getline|' \
		${WRKSRC}/radtest/input.l ${WRKSRC}/radtest/input.c

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	( cd ${WRKSRC}/examples && ${COPYTREE_SHARE} .\
		${STAGEDIR}${EXAMPLESDIR}\
		"! ( -name Makefile -o -name Makefile\.* ) " )

.include <bsd.port.mk>
