# Ports collection Makefile for:	pam_krb5
# Date created:				11/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		pam_krb5
PORTVERSION=		1.0.3
CATEGORIES=		security
MASTER_SITES=		http://www.nectar.cc/distfiles/

MAINTAINER=		nectar@FreeBSD.org

MAN8=			pam_krb5.8

USE_BZIP2=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes

.if defined(PACKAGE_BUILDING)
KRB5_IMPL=		heimdal
.endif

.if defined(KRB5_IMPL) && ${KRB5_IMPL} == heimdal
LIB_DEPENDS=		krb5.18:${PORTSDIR}/security/heimdal
.if defined(HEIMDAL_HOME)
KRB5_DIR?=		${HEIMDAL_HOME}
.endif
.elif defined(KRB5_IMPL) && ${KRB5_IMPL} == mit
LIB_DEPENDS=		krb5.3:${PORTSDIR}/security/krb5
.if defined(KRB5_HOME)
KRB5_DIR?=		${KRB5_HOME}
.endif
.else
BROKEN=			You must define KRB5_IMPL to be \"mit\" or \"heimdal\"
.endif

.if defined(PREFIX)
MANDIR=			${PREFIX}/man
.else
PREFIX=			${DESTDIR}/usr
MANPREFIX=		${DESTDIR}/usr/share
MANDIR=			${PREFIX}/share/man
.endif
KRB5_DIR?=		${LOCALBASE}
CONFIGURE_ENV=		CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=		--with-krb5="${KRB5_DIR}"	\
			--with-pamdir="${PREFIX}/lib"	\
			--with-man-sect=8		\
			--mandir=${MANDIR}

post-install:
	cd ${WRKSRC} && ${MAKE} install-man

.include <bsd.port.mk>
