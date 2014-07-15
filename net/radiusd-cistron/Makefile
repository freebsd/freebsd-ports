# Created by: john@nlc.net.au
# $FreeBSD$

PORTNAME=	radiusd-cistron
PORTVERSION=	1.6.8
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.radius.cistron.nl/pub/radius/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RADIUS-compliant remote authentication and accounting server

CONFLICTS?=	freeradius-0.* gnu-radius-1.* openradius-0.*

MAKEFILE=	Makefile.BSD
RADIUS_DIR=	${PREFIX}/etc/raddb
MAKE_ENV+=	RADIUS_DIR="${RADIUS_DIR}" DESTROOT="${STAGEDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_RC_SUBR=	radiusd-cistron radrelay-cistron
DOCFILES=	COPYRIGHT INSTALL doc/ChangeLog doc/README doc/README.Y2K \
		doc/README.cisco doc/README.pam doc/README.proxy \
		doc/README.simul doc/README.usersfile

OPTIONS_DEFINE=	PAM DOCS
OPTIONS_DEFAULT=PAM
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

PLIST_SUB+=	PAMBASE="/usr/local/etc"

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/src

do-install:
.if ${PORT_OPTIONS:MPAM}
	${MKDIR} ${STAGEDIR}/etc/pam.d
.endif
	${DO_MAKE_BUILD} -C ${WRKSRC}/src install
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
