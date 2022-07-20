PORTNAME=	mod_auth_xradius
PORTVERSION=	0.4.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_auth_xradius/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Enables RADIUS authentication

LICENSE=	APACHE20

USES=		apache:2.2+ tar:bzip2
GNU_CONFIGURE=	yes
# Seems dead upstream. Don't expect a proper fix.
CFLAGS+=	-fcommon

PLIST_FILES=	${APACHEMODDIR}/mod_auth_xradius.so

.include <bsd.port.mk>
