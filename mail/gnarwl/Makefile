# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	gnarwl
PORTVERSION=	3.6
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.onyxbits.de/sites/default/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Email autoresponder that gets data from LDAP

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm
BUILD_DEPENDS=	${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed

USES=		iconv gmake
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}

.include <bsd.port.mk>
