# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpu
PORTVERSION=	1.4.3
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change Password Utility for LDAP

USES=		tar:bzip2 libtool
GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/cpu --with-ldap=${LOCALBASE}
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-DLDAP_DEPRECATED

.include <bsd.port.mk>
