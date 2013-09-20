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

LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm
BUILD_DEPENDS=	${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed

USE_GMAKE=	yes
USES=		iconv
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}

MAN8=		damnit.8 gnarwl.8
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
