# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msktutil
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Utility to manage Active Directory interoperability

LICENSE=	GPLv2

USES=		gmake ssl tar:bzip2
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
WANT_OPENLDAP_SASL=	yes

CONFIGURE_ARGS+=--with-sasldir=${LOCALBASE}

PLIST_FILES=	man/man1/msktutil.1.gz sbin/msktutil

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/msktutil

.include <bsd.port.mk>
