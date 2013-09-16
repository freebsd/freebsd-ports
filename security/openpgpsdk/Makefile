# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpgpsdk
PORTVERSION=	0.9
CATEGORIES=	security
MASTER_SITES=	http://openpgp.nominet.org.uk/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	OpenPGP SDK

BUILD_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	cunit.1:${PORTSDIR}/devel/cunit

USES=		perl5
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-idea --with-cunit=${LOCALBASE}

PLIST_FILES=	bin/openpgp lib/libops.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/openpgp ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/libops.a ${PREFIX}/lib/

.include <bsd.port.mk>
