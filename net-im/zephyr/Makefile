# New ports collection makefile for: zephyr
# Date created: 	2009-11-12
# Whom: 	Ben Kaduk <kaduk@mit.edu>
#
# $FreeBSD$
#

PORTNAME=	zephyr
PORTVERSION=	3.0
CATEGORIES=	net-im
MASTER_SITES=	http://zephyr.1ts.org/export/2552/distribution/

MAINTAINER=	kaduk-fbsd@mit.edu
COMMENT=	An enterprise-scale distributed messaging system

LICENSE=	MIT

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
USE_RC_SUBR=	zhm
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes

MAN1=	zephyr.1 zaway.1 zctl.1 zleave.1 zlocate.1 znol.1 zwrite.1 zwgc.1
MAN8=	zhm.8 zephyrd.8 zstat.8 zshutdown_notify.8

OPTIONS=	HEIMDAL	"Use Heimdal Kerberos for ss/com_err"	no

.include <bsd.port.options.mk>

# On 6.X zephyr install libzephyr.so.4 and libzephyr.so.4.0 for others
.if ${OSVERSION} < 700000
PLIST_SUB+=	ZEPHYR_SHVERSION=4
BROKEN=		bad plist
.else
PLIST_SUB+=	ZEPHYR_SHVERSION=4.0
.endif

.if defined(WITH_HEIMDAL)
LIB_DEPENDS+=	ss.1:${PORTSDIR}/security/heimdal
.if defined(HEIMDAL_HOME)
KRB5_DIR?=	${HEIMDAL_HOME}
.else
KRB5_DIR?=	${LOCALBASE}
.endif
.else
LIB_DEPENDS+=	ss.2:${PORTSDIR}/devel/e2fsprogs-libss
KRB5_DIR?=	${DESTDIR}/usr
.endif

# it is an upstream bug that --with-krb5 needs a path
CONFIGURE_ARGS=	--with-krb5="${KRB5_DIR}"
CONFIGURE_ENV+= LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"

.include <bsd.port.mk>
