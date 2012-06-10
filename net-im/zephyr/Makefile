# New ports collection makefile for: zephyr
# Date created: 	12 November 2009
# Whom: 	Ben Kaduk <kaduk@mit.edu>
#
# $FreeBSD$
#

PORTNAME=	zephyr
DISTVERSION=	3.0.1
CATEGORIES=	net-im
MASTER_SITES=	http://zephyr.1ts.org/export/2642/distribution/

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

OPTIONS=	HEIMDAL	"Use Heimdal Kerberos for ss/com_err"	off

.include <bsd.port.options.mk>

.if defined(WITH_HEIMDAL)
BROKEN=		bad depobj
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

.include <bsd.port.mk>
