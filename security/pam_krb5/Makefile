# Ports collection Makefile for:	pam_krb5
# Date created:				11/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		pam_krb5
PORTVERSION=		1.0
PORTREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.fcusack.com/soft/

MAINTAINER=		nectar@FreeBSD.org

WRKSRC=			${WRKDIR}/pam_krb5
PREFIX?=		${DESTDIR}/usr
MANPREFIX?=		${DESTDIR}/usr/share
MAKE_ENV=		PREFIX="${PREFIX}" MANPREFIX="${MANPREFIX}" \
			KRB5BASE="${KRB5BASE}" KRB5_IMPL="${KRB5_IMPL}"

MAN8=			pam_krb5.8

.include <bsd.port.pre.mk>

# Try hard to figure out which Kerberos implementation we should use to
# build this thing.  There are three possibilities:
#   Heimdal in the base system -- XXX disabled for now (missing libraries)
#   Heimdal from ports
#   MIT Kerberos from ports
.if defined(KRB5BASE) && defined(KRB5_IMPL)
# the user thinks he knows what he is doing, so let it be
.elif exists(/usr/include/heim_err.h) && defined(REALLY_WANT_BASE) && (${REALLY_WANT_BASE} == "yes")
KRB5BASE=/usr
KRB5_IMPL="heimdal"
.elif defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/include/heim_err.h)
KRB5BASE=${HEIMDAL_HOME}
KRB5_IMPL=heimdal
LIB_DEPENDS+=		krb5.15:${PORTSDIR}/security/heimdal
.elif exists(${LOCALBASE}/include/heim_err.h)
KRB5BASE=${LOCALBASE}
KRB5_IMPL=heimdal
LIB_DEPENDS+=		krb5.15:${PORTSDIR}/security/heimdal
.elif defined(KRB5_HOME) && exists(${KRB5_HOME}/include/mit-sipb-copyright.h)
KRB5BASE=${KRB5_HOME}
KRB5_IMPL=mit
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
.elif exists(${LOCALBASE}/include/mit-sipb-copyright.h)
KRB5BASE=${LOCALBASE}
KRB5_IMPL=mit
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
.else
BROKEN=			"No version of Kerberos is installed."
.endif

.include <bsd.port.post.mk>
