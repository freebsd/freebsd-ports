# Created by: Stefan Grundmann
# $FreeBSD$

PORTNAME=	pam_ocra
PORTVERSION=	1.2
CATEGORIES=	security

MAINTAINER=	sg2342@googlemail.com
COMMENT=	RFC6287 (OCRA) PAM module

LICENSE=	BSD2CLAUSE

USES=		uidfix
USE_OPENSSL=	yes

USE_GITHUB=	yes

GH_ACCOUNT=	sg2342

PLIST_FILES=	lib/pam_ocra.so \
		lib/pam_ocra.so.0 \
		sbin/ocra_tool \
		man/man8/pam_ocra.8.gz \
		man/man8/ocra_tool.8.gz

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000015
WITH_OPENSSL_PORT=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif

.include <bsd.port.mk>
