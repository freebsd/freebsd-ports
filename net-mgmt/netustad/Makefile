# New ports collection makefile for:   netustad
# Date created:                 9 February 2005
# Whom:                         Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	netustad
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.enderunix.org/netustad/

MAINTAINER=	ozkan@enderunix.org
COMMENT=	A Web based admin tool that manages network services

#MAN8=		netustad.8 netustadpasswd.8
#MAN5=		netustad.conf.5

USE_RC_SUBR=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
OPTIONS=	SSL "Use netUstad with SSL support" on

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=    ${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=   ${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--without-nls
.endif

.if defined(NOPORTDOCS)
#make portlint happy :)
.endif

SED_SCRIPT+=	-e '{ s,%%PREFIX%%,${PREFIX},g; }'

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/netustad.sh >${WRKDIR}/netustad.sh

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} ${SED_SCRIPT}
	${INSTALL_SCRIPT} ${WRKDIR}/netustad.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
