# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	softhsm
PORTVERSION=	1.3.8
CATEGORIES=	security
MASTER_SITES=	http://dist.opendnssec.org/source/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Software implementation of a Hardware Security Module (HSM)

LICENSE=	BSD2CLAUSE ISCL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	End-of-life announced, update to softhsm2 ASAP.
EXPIRATION_DATE=	2019-10-01

LIB_DEPENDS=	libbotan-1.10.so:security/botan110 \
		libsqlite3.so:databases/sqlite3

USES=		libtool
GNU_CONFIGURE=	yes
# !!!!!!!!!!!!
# Changing the localstatedir is a huge POLA violation. Please leave it alone.
# !!!!!!!!!!!!!!
CONFIGURE_ARGS=	--with-botan=${LOCALBASE} --with-sqlite3=${LOCALBASE} \
		--localstatedir=/var
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFLICTS=	softhsm2-[0-9]*

.include <bsd.port.mk>
