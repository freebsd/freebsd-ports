# Created by: joseph@randomnetworks.com

PORTNAME=	adtool
PORTVERSION=	1.3.3
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://gp2x.org/adtool/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Active Directory administration tool

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes

CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}

PLIST_FILES=	bin/adtool \
		etc/adtool.cfg.dist \
		man/man1/adtool.1.gz

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.mk>
