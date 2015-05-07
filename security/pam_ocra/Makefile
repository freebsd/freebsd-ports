# Created by: Stefan Grundmann
# $FreeBSD$

PORTNAME=	pam_ocra
PORTVERSION=	1.2
CATEGORIES=	security

MAINTAINER=	sg2342@googlemail.com
COMMENT=	RFC6287 (OCRA) PAM module

LICENSE=	BSD2CLAUSE

USES=		uidfix

USE_GITHUB=	yes

GH_ACCOUNT=	sg2342

PLIST_FILES=	lib/pam_ocra.so \
		lib/pam_ocra.so.0 \
		sbin/ocra_tool \
		man/man8/pam_ocra.8.gz \
		man/man8/ocra_tool.8.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000015
WITH_OPENSSL_PORT=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif

# we need to .include bsd.openssl.mk manually here.because USE_OPENSSL only
# works when it is defined before bsd.port{.pre}.mk is .included.
# This makes it currently impossible to combine this macro with OSVERSION to
# conditionally select WITH_OPENSSL_PORT for OSVERSIONS before 1000015.
.include "${PORTSDIR}/Mk/bsd.openssl.mk"

.include <bsd.port.post.mk>
