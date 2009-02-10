# New ports collection makefile for:	openpgpsdk
# Date created:		2009-02-10
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openpgpsdk
PORTVERSION=	0.9
CATEGORIES=	security
MASTER_SITES=	http://openpgp.nominet.org.uk/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	OpenPGP SDK

BUILD_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	cunit.1:${PORTSDIR}/devel/cunit

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-idea --with-cunit=${LOCALBASE}

PLIST_FILES=	bin/openpgp lib/libops.a

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=		does not build on 6.x.
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/openpgp ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/libops.a ${PREFIX}/lib/

.include <bsd.port.post.mk>
