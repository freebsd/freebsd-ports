# New ports collection makefile for:   netustad
# Date created:                 9 February 2005
# Whom:                         Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	netustad
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.enderunix.org/netustad/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Web based admin tool that manages network services

#MAN8=		netustad.8 netustadpasswd.8
#MAN5=		netustad.conf.5

USE_RC_SUBR=	${PORTNAME}
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
OPTIONS=	SSL "Use netUstad with SSL support" on

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

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
post-patch:
	${REINPLACE_CMD} "s/^install-data-am:.*/install-data-am:/" ${WRKSRC}/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
