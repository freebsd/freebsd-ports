# Created by: Martti Kuparinen <martti.kuparinen@iki.fi>
# $FreeBSD$

PORTNAME=	isakmpd
PORTVERSION=	20041207
PORTREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	LOCAL/simon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenBSD IKE daemon

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netipsec/ipsec.h) && !exists(/usr/include/netinet6/ipsec.h)
BROKEN=		requires IPsec support
.endif

# If keynote is in use, bring the dependency
.if defined(USE_KEYNOTE)
BUILD_DEPENDS+=	keynote:security/keynote
.endif

USES=		uidfix
USE_RC_SUBR=	isakmpd
MAKE_ENV+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

USE_OPENSSL=	yes

MAKE_JOBS_UNSAFE=	yes
.include <bsd.port.pre.mk>

OPENSSLINC?=	/usr/include
OPENSSLLIB?=	/usr/lib
MAKE_ENV+=	OPENSSLINC="${OPENSSLINC}" OPENSSLLIB="${OPENSSLLIB}"

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
.for f in conf.h ike_auth.c isakmpd.8 isakmpd.conf.5 isakmpd.policy.5 policy.h
	${REINPLACE_CMD} -e "s!/etc/!${PREFIX}/etc/!" ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e "s!netinet6/ipsec.h!netipsec/ipsec.h!" \
		${WRKSRC}/sysdep/freebsd/sysdep-os.h

.include <bsd.port.post.mk>
