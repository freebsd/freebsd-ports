# New ports collection Makefile for:	ISAKMP daemon
# Date created:				Fri May 11 18:20:02 EEST 2001
# Whom:					Martti Kuparinen <martti.kuparinen@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	isakmpd
PORTVERSION=	20041207
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	simon

MAINTAINER=	simon@FreeBSD.org
COMMENT=	OpenBSD IKE daemon

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
BROKEN=		"requires IPsec support"
.endif

# If keynote is in use, bring the dependency
.if defined(USE_KEYNOTE)
BUILD_DEPENDS+=	keynote:${PORTSDIR}/security/keynote
.endif

USE_OPENSSL=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/isakmpd
MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

MAN5=		isakmpd.conf.5 isakmpd.policy.5
MAN8=		certpatch.8 isakmpd.8
MANCOMPRESSED=	yes

post-patch:
.for f in conf.h ike_auth.c isakmpd.8 isakmpd.conf.5 isakmpd.policy.5 policy.h
	${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
