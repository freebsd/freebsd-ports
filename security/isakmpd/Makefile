# New ports collection Makefile for:	ISAKMP daemon
# Date created:				Fri May 11 18:20:02 EEST 2001
# Whom:					Martti Kuparinen <martti.kuparinen@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	isakmpd
PORTVERSION=	20041207
PORTREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	simon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenBSD IKE daemon

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netipsec/ipsec.h) && !exists(/usr/include/netinet6/ipsec.h)
BROKEN=		requires IPsec support
.endif

# If keynote is in use, bring the dependency
.if defined(USE_KEYNOTE)
BUILD_DEPENDS+=	keynote:${PORTSDIR}/security/keynote
.endif

USE_RC_SUBR=	isakmpd.sh
WRKSRC=		${WRKDIR}/isakmpd
MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man LC_ALL=C

MAN5=		isakmpd.conf.5 isakmpd.policy.5
MAN8=		certpatch.8 isakmpd.8
MANCOMPRESSED=	yes

USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

OPENSSLINC?=	/usr/include
OPENSSLLIB?=	/usr/lib
MAKE_ENV+=	OPENSSLINC="${OPENSSLINC}" OPENSSLLIB="${OPENSSLLIB}"

post-patch:
.for f in conf.h ike_auth.c isakmpd.8 isakmpd.conf.5 isakmpd.policy.5 policy.h
	${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/${f}
.endfor
.if ${OSVERSION} > 700050
	@${REINPLACE_CMD} -e "s!netinet6/ipsec.h!netipsec/ipsec.h!" \
		${WRKSRC}/sysdep/freebsd/sysdep-os.h
.endif

.include <bsd.port.post.mk>
